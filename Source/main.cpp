#include <iostream>

#include "../Core/CLI-args/help.cpp"


#include <functional>  // for function
#include <memory>      // for shared_ptr, allocator, __shared_ptr_access
#include <string>      // for string, basic_string
#include <vector>      // for vector
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Slider, Checkbox, Vertical, Renderer, Button, Input, Menu, Radiobox, Toggle
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for separator, operator|, Element, size, xflex, text, WIDTH, hbox, vbox, EQUAL, border, GREATER_THAN

using namespace ftxui;

int main(int argc, char const *argv[])
{
  playbackmenu::ShowLocalStream();
  return 0;
}