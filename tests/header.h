// Decorator design pattern

#include <iostream>
#include <memory>

// interface for Window and Decorator
struct IWindow {
    virtual void draw() const = 0;
    virtual ~IWindow() = default;
};

// concrete Window
class Window : public IWindow {
  public:
    void draw() const override { std::cout << "Basic Window\n"; }
};

// fancy Window
class FancyWindow : public Window {
  public:
    void draw() const override { std::cout << "Fancy Window\n"; }
};

// basic Decorator
class Decorator : public IWindow {
    std::unique_ptr<IWindow> _window; // has a
  public:
    explicit Decorator(std::unique_ptr<IWindow> window)
        : _window{std::move(window)} {}
    void draw() const override {
        _window->draw(); // delegate responsibility
    }
};

// add borders
class BorderDecorator : public Decorator {
  public:
    explicit BorderDecorator(std::unique_ptr<IWindow> window)
        : Decorator(std::move(window)) {}
    void draw() const override {
        Decorator::draw();
        std::cout << "\twith Border\n";
    }
};

// add scrollbars
class ScrollBarDecorator : public Decorator {
  public:
    explicit ScrollBarDecorator(std::unique_ptr<IWindow> window)
        : Decorator(std::move(window)) {}
    void draw() const override {
        Decorator::draw();
        std::cout << "\twith ScrollBar\n";
    }
};
