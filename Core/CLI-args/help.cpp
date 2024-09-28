#include <iostream>
#include <string>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

using namespace ftxui;

namespace  helpmenu
{
	void HelpMenu()
	{
		Element document = 
			vbox({
					vbox({text("LYZC-Player By LYZENCORE-9 (DISTROXYDE 8)") | bold | underlined | color(Color::Magenta)}),
					vbox({text("1234") | bold | color(Color::Blue)}),


			}); 


		auto screen = Screen::Create(Dimension::Full(),Dimension::Fit(document));
		Render(screen, document);
		screen.Print();
	}
	
}