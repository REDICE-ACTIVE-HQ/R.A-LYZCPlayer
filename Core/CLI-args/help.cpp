#include <iostream>
#include <string>
#include <vector>

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Radiobox, Horizontal, Menu, Renderer, Tab
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"
#include <ftxui/screen/screen.hpp>

using namespace ftxui;

Component Window(std::string title, Component component) {
  return Renderer(component, [component, title] {  //
    return window(text(title), component->Render()) | flex;
  });
}


namespace  playbackmenu
{
	std::vector<std::string> playback_tab_entries = {"Local Stream", "Online Stream", "Core Info"};
  std::vector<std::string> playback_tab_description = {"Desc 1", "Desc 2", "Version 0.0.0.0"};
  std::vector<Element> playback_test_array = {text("1"), text("2"), text("3")};

  void ShowLocalStream()
	{
    auto screen = ScreenInteractive::Fullscreen();
    int tab_menu_selected = 0;
    int general_tab_selected = 0;

    Component general_tab_menu = Container::Vertical(
      {
        Window("Playback Help Menu", Menu(&playback_tab_entries, &tab_menu_selected)) | color(Color::GreenLight),
      }, &general_tab_selected);

    auto rendrer = Renderer([&] 
    {
      return window(text("Content"), 
                    vbox({
                      //color(Color::White, text("*" + playback_tab_description[tab_menu_selected])),
                      color(Color::White, playback_test_array[tab_menu_selected]),
                    })) | flex | color(Color::Yellow);


    });

    Component main_container = Container::Horizontal({
      general_tab_menu,
      rendrer,
    });

    screen.Loop(main_container);


	}

  
	
}

/*
auto screen = ScreenInteractive::TerminalOutput();

  std::vector<std::string> entries = {
      "entry 1",
      "entry 2",
      "entry 3",
  };
  int selected = 0;

  MenuOption option;
  option.on_enter = screen.ExitLoopClosure();
  auto menu = Menu(&entries, &selected, option);

  screen.Loop(menu);

  std::cout << "Selected element = " << selected << std::endl;


*/








/*

Element document = {
                        hbox({
                              vbox(text("test")),
                              separator(),
                              vbox({ 
                                text("vertical text"),
                              }),
                        }) | border,                      
    };

    auto screen = Screen::Create(Dimension::Fullscreen());
    Render(screen, document);
    screen.Print();*/