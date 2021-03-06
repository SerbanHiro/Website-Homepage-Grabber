// Windows only program
#include <iostream>
#include <windows.h>
#include <cstring>
#pragma comment(lib, "Urlmon.lib")
// Made in Visual Studio 2019
using namespace std;
int main()
{
    // Read website url
    const wchar_t* website_url_L;
    string website_url;
    string httpswebsite;
    wstring website_wide_L;
    cout << "Website Url: ";
    cin >> website_url;
    httpswebsite = "https://" + website_url;
    website_wide_L.assign(httpswebsite.begin(), httpswebsite.end());
    website_url_L = website_wide_L.c_str();
    // Read website url

    // Folder Name + Save the source code from the website home page
    const wchar_t* destination_file;
    string folder_init; // folder initialize
    string folder_fin; // folder finalize
    wstring file;
    cout << "Folder Name: ";
    cin >> folder_init;
    folder_fin = folder_init + ".txt";
    file.assign(folder_fin.begin(), folder_fin.end());

    destination_file = file.c_str(); 
    // Folder Name + Save the source code from the website home page

    // URLDownloadToFile function
    if (S_OK == URLDownloadToFile(NULL, website_url_L, destination_file, 0, NULL))
    {
        cout << "Source Code saved in " << folder_init<<".txt";
        return 0;
    }
    else if(E_OUTOFMEMORY==0)
    {
        cout << "Out of memory";
        return 0;
    }
    else 
    {
        cout << "Invalid Website";
        return 0;
    }
}
/*
REQUIREMENTS
Minimum supported client

Windows XP

Minimum supported server

Windows 2000 Server
*/