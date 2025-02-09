#pragma once

#include <string>
#include <memory>

#include "Utility/Flags.h"
#include "Utility/Geometry/Size.h"
#include "Utility/Geometry/Point.h"
#include "Utility/Geometry/Margins.h"

#include "PlatformOpenGLOptions.h"
#include "PlatformEnums.h"

class PlatformOpenGLContext;


/**
 * Abstraction for accessing platform-specific window API.
 *
 * This class is essentially an API handle and doesn't hold any state. Windows users can think about it as
 * a thin wrapper atop of `HWND`, so a name like `PlatformWindowApiHandle` might've been more suitable here.
 * Fortunately we're not writing in Java and prefer shorter names.
 *
 * Event processing & state storage can be done by subclassing `PlatformEventHandler` and then using it when calling
 * into `PlatformEventLoop`.
 */
class PlatformWindow {
 public:
    virtual ~PlatformWindow() = default;

    virtual void setTitle(const std::string &title) = 0;
    virtual std::string title() const = 0;

    virtual void resize(const Sizei &size) = 0;
    virtual Sizei size() const = 0;

    virtual void setPosition(const Pointi &pos) = 0;
    virtual Pointi position() const = 0;

    virtual void setVisible(bool visible) = 0;
    virtual bool isVisible() const = 0;

    virtual void setResizable(bool resizable) = 0;
    virtual bool isResizable() const = 0;

    virtual void setWindowMode(PlatformWindowMode mode) = 0;
    virtual PlatformWindowMode windowMode() = 0;

    virtual void setGrabsMouse(bool grabsMouse) = 0;
    virtual bool grabsMouse() const = 0;

    virtual void setOrientations(PlatformWindowOrientations orientations) = 0;
    virtual PlatformWindowOrientations orientations() = 0;

    virtual Marginsi frameMargins() const = 0;

    /**
     * @return                          System handle of a window, e.g. `HWND` on windows or `NSWindow *` on mac.
     */
    virtual uintptr_t systemHandle() const = 0;

    virtual void activate() = 0;

    virtual std::unique_ptr<PlatformOpenGLContext> createOpenGLContext(const PlatformOpenGLOptions &options) = 0;
};
