#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstring>

#include "ftxui/dom/elements.hpp"
#include <ftxui/screen/screen.hpp>

#include "../CLI-args/help.cpp"

using namespace ftxui;


namespace Parser
{	
	std::string arguments[12+1];
	int argcm = 0;
	
	void MainPlaybackCore();


	void Init(int &args_num, const char* input_args[])
	{
		argcm = args_num;
		int arrayindex = 0;
		for(int i = 1; i < args_num; i++)
		{
			arguments[arrayindex] = input_args[i];
			arrayindex++;
		}

		if(arguments[0] == "--playback")
		{
			MainPlaybackCore();
		}
	}

	void MainPlaybackCore()
	{
		if(arguments[1] == "-lf" || arguments[1] == "--localfile")
		{
			std::cout << arguments[2] << '\n';
		}
		else if(arguments[1] == "-of" || arguments[1] == "--onlinefile")
		{
			std::cout << "URL :" << arguments[2] << '\n';
		}
		else if(arguments[1] == "")
		{
			Element document = {
				vbox({
					borderRounded(text("	- R.A-LYZCPlayer Report -	")) | center | bold | flex | color(Color::GreenLight),
					text("* [Error] : Invalid Argument (empty string)") | bold | color(Color::Red),
					text("* [Hint] : do --playback --help or --playback -h") | bold | color(Color::Cyan),
				}),
			};
			auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
			Render(screen, document);
			screen.Print();
		}
		else if(arguments[1] == "-h" || arguments[1] == "--help")
		{
			PlaybackHelp::ShowHelpMenu();
		}
		else
		{
			Element document = {
				vbox({
					borderRounded(text("	- R.A-LYZCPlayer Report -	")) | center | bold | flex | color(Color::GreenLight),
					text("* [Error] : Invalid Option") | bold | color(Color::Red),
					text("* [Hint] : do --playback --help or --playback -h") | bold | color(Color::Cyan),
				}),
			};
			auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
			Render(screen, document);
			screen.Print();
		}
	}

}
