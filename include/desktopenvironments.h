#pragma once

// global headers
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//! Interface for desktop environments
class IDesktopEnvironment {
protected:
    //! Call a program, retrieve its stdout, cut off
    static bool callProgramAndGetFirstLineOfOutput(const string command, string &output);
    //! Check whether a string starts with a given prefix
    static bool stringStartsWith(const string str, const string prefix);
    //! Removes newline characters from the end of a string
    static void stripNewlineCharacters(string &str);
    //! Converts a string to lower case in-place
    static void stringToLower(string &str);
    //! Searches a file for a line containing the given pattern
    static bool searchLineInFile(ifstream &file, const string pattern, string &line);
    //! Searches for a specific line in the GTK RC (usually ~/.gtkrc-2.0)
    static bool searchLineInGtkRc(const string pattern, string &output);
    //! Tries to find the GTK font in the GTK RC
    static bool getFontFromGtkRc(string &font);
    //! Removes quotation marks ' and " from a string
    static void removeQuotationMarks(string &str);
    //! Tries to resolve the path to the configuration home (e.g. ~/.config)
    static string pathToConfigHome();

public:
    //! Creates a new instance for the given desktop environment name, or nullptr if the DE is not supported
    static IDesktopEnvironment* getInstance(const string name);
    //! Attempts to detect the current desktop environment, and returns an instance of the according class
    static IDesktopEnvironment* getInstance();

public:
    //! Gets the font the DE uses for GTK applications
    virtual bool gtkInterfaceFont(string &font) = 0;
    //! Returns the name of the current desktop environment class
    virtual string name() = 0;
};
