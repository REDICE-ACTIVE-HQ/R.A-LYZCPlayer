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

namespace  PlaybackHelp
{
	std::vector<std::string> playback_tab_entries = {"Local Stream", "Online Stream", "Core Info"};
  std::vector<Element> playback_tab_description = {
    vbox({
      text("** Local Stream Help **") | center | bold | blink | color(Color::Blue), text(""),
      text("** 1 - Information") | bold | color(Color::Yellow),
      text(""), bold(text("Local Stream Mode is a mode for playing files in your computer (not internet)")),
      bold(text("it means the player can only play files in your computer (local stream) and he can't play")),
      bold(text("files in internet like :")), text(""),
      text("https://www.youtube.com , https://soundclound.com") | bold | color(Color::Cyan), 
      text(""),
      text("** 2 - Commands") | bold | color(Color::Yellow), text(""),
      text("NULL Description"),
    }), 
    vbox({
      text("** Online Stream Help **") | center | bold | blink | color(Color::Blue), text(""),
      text("** 1 - Information") | bold | color(Color::Yellow),
      text(""), bold(text("Online Stream Mode is a mode for playing files in internet ")),
      bold(text("it means the player can play files in internet (Online stream) and he can play")),
      bold(text("files from websites in internet like :")), text(""),
      text("https://www.youtube.com , https://soundclound.com, and more") | bold | color(Color::Cyan), 
      text(""),
      text("** 2 - Commands") | bold | color(Color::Yellow), text(""),
      text("NULL Description"),
    }), 

    vbox({
      text("** Core Info **") | center | bold | blink | color(Color::Blue), text(""),
      text("** Core Version Info") | bold | color(Color::Yellow) , text(""), 
      text("* Major Version : 0.1.1") | bold | color(Color::Cyan),
      text("* Minor Version : 0.0.1") | bold | color(Color::Cyan),
      text("* Core Status Version : Unstable - Alpha") | bold | color(Color::Cyan),
      text("* Core Type : File Stream") | bold | color(Color::Cyan),
      text("* Core Build Version : 0.1.1-0.0.1-(M.U)[A] ") | bold | color(Color::Cyan), text(""), text(""),
      text("R.A-C.GA LYZCPlayer - LYZENCORE 9 All Copyrights Reserved (3.11.2024)") | bold | center | color(Color::Green),
    })
  };

  void ShowHelpMenu()
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
                      color(Color::White, playback_tab_description[tab_menu_selected]),
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