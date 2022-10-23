#pragma once

#include <gl4/wgl/adapter.hpp>
#include <core/base/platform.hpp>
#include <core/concurrency/generator.hpp>
#include <core/gfx/video_mode.hpp>

namespace morpheus::gfx::gl4::wgl
{

using VideoMode = gfx::VideoMode;


concurrency::Generator<VideoMode> enumerateVideoModes(Adapter const& adapter);

} // namespace morpheus::gfx::gl4::wgl