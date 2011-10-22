/*
* copyright (c) 2010 Sveriges Television AB <info@casparcg.com>
*
*  This file is part of CasparCG.
*
*    CasparCG is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    CasparCG is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with CasparCG.  If not, see <http://www.gnu.org/licenses/>.
*
*/
#pragma once

#include "pixel_format.h"
#include "../../video_format.h"

#include <common/memory/safe_ptr.h>

#include <concrt.h>
#include <concrt_extras.h>

#include <boost/noncopyable.hpp>
#include <boost/thread/future.hpp>

namespace caspar { namespace core {
	
class write_frame;
struct video_format_desc;
		
struct frame_factory : boost::noncopyable
{
	virtual safe_ptr<write_frame> create_frame(const void* video_stream_tag, const pixel_format_desc& desc) = 0;
	virtual safe_ptr<write_frame> create_frame(const void* video_stream_tag, size_t width, size_t height, pixel_format::type pix_fmt = pixel_format::bgra)
	{	
		// Create bgra frame
		core::pixel_format_desc desc;
		desc.pix_fmt = pix_fmt;
		desc.planes.push_back( core::pixel_format_desc::plane(width, height, 4));
		return create_frame(video_stream_tag, desc);
	}
	
	virtual boost::unique_future<safe_ptr<write_frame>> create_frame2(const void* video_stream_tag, const pixel_format_desc& desc) = 0;

	virtual video_format_desc get_video_format_desc() const = 0; // nothrow
};
	
class concrt_frame_factory : public frame_factory
{	
	safe_ptr<frame_factory> factory_;
public:
	concrt_frame_factory(const safe_ptr<frame_factory>& factory) 
		: factory_(factory)
	{
	}
		
	virtual safe_ptr<write_frame> create_frame(const void* tag, const pixel_format_desc& desc)
	{
		auto frame = factory_->create_frame2(tag, desc);

		Concurrency::wait(0);

		if(!frame.has_value())
		{
			Concurrency::scoped_oversubcription_token oversubscribe;
			frame.wait();
		}
		return frame.get();
	}

	virtual boost::unique_future<safe_ptr<write_frame>> create_frame2(const void* video_stream_tag, const pixel_format_desc& desc)
	{
		return factory_->create_frame2(video_stream_tag, desc);
	}

	virtual video_format_desc get_video_format_desc() const
	{
		return factory_->get_video_format_desc();
	}
};

}}