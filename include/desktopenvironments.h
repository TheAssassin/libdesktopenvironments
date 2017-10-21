#pragma once

// global headers
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

//! Interface for desktop environments
class IDesktopEnvironment {
protected:
    //! Call a program, retrieve its stdout, cut off
    static bool callProgramAndGetFirstLineOfOutput(std::string command, std::string &output);
    //! Check whether a string starts with a given prefix
    static bool stringStartsWith(std::string str, std::string prefix);
    //! Removes newline characters from the end of a string
    static void stripNewlineCharacters(std::string &str);
    //! Converts a string to lower case in-place
    static void stringToLower(std::string &str);
    //! Searches a file for a line containing the given pattern
    static bool searchLineInFile(std::ifstream &file, std::string pattern, std::string &line);
    //! Searches for a specific line in the GTK RC (usually ~/.gtkrc-2.0)
    static bool searchLineInGtkRc(std::string pattern, std::string &output);
    //! Tries to find the GTK font in the GTK RC
    static bool getFontFromGtkRc(std::string &font);
    //! Removes quotation marks ' and " from a string
    static void removeQuotationMarks(std::string &str);
    //! Tries to resolve the path to the configuration home (e.g. ~/.config)
    static std::string pathToConfigHome();
    //! Runs the type command to detect whether applications are installed, and if they are, returns the full path to them
    static bool type(std::string programName, std::string &programPath);

public:
    //! Creates a new instance for the given desktop environment name, or nullptr if the DE is not supported
    static IDesktopEnvironment* getInstance(std::string name);
    //! Attempts to detect the current desktop environment, and returns an instance of the according class
    static IDesktopEnvironment* getInstance();

public:
    //! Gets the font the DE uses for GTK applications
    virtual bool gtkInterfaceFont(std::string &font) = 0;
    //! Returns the name of the current desktop environment class
    virtual std::string name() = 0;
};
