#pragma once

#include <morpheus/gfx/platform/render_window.hpp>

#include <X11/Xlib.h>

#include <memory>

namespace morpheus::gfx::x11
{

struct XCloseDisplayDispatch
{
    auto operator()(::Display* display)
    {
        XCloseDisplay(display);
    }
};

//using XCloseDisplayDispatch = decltype([](::Display* display){ XCloseDisplay(display); });
using DisplayPtr = std::unique_ptr<::Display, XCloseDisplayDispatch>;

struct XDestroyDisplayDispatch
{
    explicit XDestroyDisplayDispatch(::Display* display) noexcept
    : mDisplay(display)
    {}

    using pointer = ::Window;

    auto operator()(pointer window)
    {
        XDestroyWindow(mDisplay, window);
    }

private:
    ::Display* mDisplay = nullptr;
};

using WindowPtr = std::unique_ptr<Window, XDestroyDisplayDispatch>;

/*! \class RenderWindow
        A specialisation of the render window for the x11 platform on Linux.
 */
class RenderWindow : protected gfx::RenderWindow {
public:
    using Config = gfx::RenderWindow::Config;

    explicit RenderWindow(Config const& config = Config{}){}

    explicit RenderWindow(RenderWindow const&) = delete;
    RenderWindow& operator=(RenderWindow const&) = delete;

    explicit RenderWindow(RenderWindow&&) noexcept = delete;
    RenderWindow& operator=(RenderWindow&&) noexcept = delete;

    ~RenderWindow() = default;

    //! The width in pixels of the render target.
    [[nodiscard]] std::uint16_t width() const noexcept { return gfx::RenderTarget::width(); }

    //! The height in pixels of the render target.
    [[nodiscard]] std::uint16_t height() const noexcept { return gfx::RenderTarget::height(); }

    //! The colour depth of the pixels of the render target.
    [[nodiscard]] std::uint16_t colourDepth() const noexcept { return gfx::RenderTarget::colourDepth(); }

    //    bool isHidden() const noexcept
    //    bool isFocus() const noexcept

    /// \copydoc gfx::RenderWindow::fullScreen()
    [[nodiscard]] bool fullScreen() const noexcept { return gfx::RenderWindow::fullScreen(); }

    /// Queries if the window is visible;
    [[nodiscard]] bool visible() const noexcept;

    //    void isHidden(bool const hidden) const noexcept
    //    void isFocus(bool const focus) const noexcept
    //    void isVisible(bool const visible) const noexcept

//    void resize();


private:

    /// \struct ReleaseResources
    ///     Allows std::unique_ptr handles to override the expect pointer type and to define a lambda to execute
    ///     clean-up.
    template<typename T>
    struct ReleaseResources
    {
        using pointer = T;
        std::function<void()> releaser;
        void operator()(pointer) { releaser(); }
    };

    /// \typedef ResourceWrapper
    ///     Defines a type for wrapping a resource an calling clean up.
    /// \note
    ///     Depending on the resource definition operator*() and operator->() may not make sense for the type and fail
    ///     to compile. In such cases default to using the get() method instead.
    template<typename T>
    using ResourceWrapper = std::unique_ptr<T, ReleaseResources<T>>;



//    // Requires std::experimental::unique_resource (or boost scope equivalent)
//    DisplayPtr mDisplay;
//    WindowPtr mWindow;
};

} // namespace morpheus::gfx::x11
