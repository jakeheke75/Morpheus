#pragma once

namespace morpheus::gfx::gl4
{

/*! \class types
        Provides helper methods for mapping from native types to the underlying rendering API.
 */
class type_mapping {
public:
    /// \name Life cycle
    ///@{
    /*! Constructs a video mode with the specified parameters.
        \param[in] width
             The width in pixels of the video mode.
        \param[in] height
             The height in pixels of the video mode.
        \param[in] colourDepth
             The colour depth of the pixels of the render target.
     */
    type_mapping(
 //       const std::uint32_t width,
 //       const std::uint32_t height,
 //       const std::uint32_t colourDepth
    );
    ///@}



    //! The width in pixels of the render target.
//    std::uint16_t width() const noexcept { return mWidth; }

    //! The height in pixels of the render target.
//    std::uint16_t height() const noexcept { return mHeight; }

    //! The colour depth of the pixels of the render target.
//    std::uint16_t colour_depth() const noexcept { return mColourDepth; }

    //! The colour depth of the pixels of the render target.
//    std::uint16_t refresh_rate() const noexcept { return mRefreshRate; }
private:
    /// \name Data Members
    ///@{
    //! The width in pixels of the video mode.
//    const std::uint16_t mWidth = 0;
    //! The height in pixels of the video mode.
//    const std::uint16_t mHeight = 0;
    //! The colour depth of the pixels of the video mode.
//    const std::uint16_t mColourDepth = 0;
    //! The refresh rate of the video mode.
//    const std::uint16_t mRefreshRate = 0;
    ///@}
};

} // namespace morpheus::gfx::d3d12
