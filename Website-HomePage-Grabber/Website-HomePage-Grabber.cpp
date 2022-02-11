// Windows only program
#include <iostream>
#include <windows.h>
#include <cstring>
#pragma comment(lib, "Urlmon.lib")
// Made in Visual Studio 2019
using namespace std;
void file_location(const string file)
{
    size_t file_loc = file.find_last_of("\\");
    cout<<"Saved in: "<<file.substr(0, file_loc)<<"\n";
}
int main(int argc,char *argv[])
{
    // Read website url
    //const wchar_t* website_url_L; ==> v1.0.0

    string website_url;
    string httpswebsite;
    wstring website_wide_L;
    cout << "Website Url: ";
    cin >> website_url; cin.ignore();
    // verify if the site is real or not v1.0.1
    size_t check_website_reality=website_url.find_last_of(".");
    if (website_url.substr(0, check_website_reality) == website_url)
    {
        cout << "The website has been mistyped" << endl;
        return EXIT_FAILURE;
    }
    // is the site real? v1.0.1
    string check_if_site_has_https;
    check_if_site_has_https.append(website_url, 0,8);

    // https:// and http:// check
    if (check_if_site_has_https == "https://"||check_if_site_has_https == "http://")
        httpswebsite = website_url;
    else httpswebsite ="https://" + website_url;
    // https:// check

    website_wide_L.assign(httpswebsite.begin(), httpswebsite.end());

    // website_url_L = website_wide_L.c_str(); ==> v1.0.0
    // Read website url

    // Folder Name + Save the source code from the website home page
    // const wchar_t* destination_file; ==> v1.0.0

    string folder_init; // folder initialize
    string folder_fin; // folder finalize
    wstring file;
    cout << "Folder Name: ";
    cin >> folder_init; cin.ignore();
    folder_fin = folder_init + ".txt";
    file.assign(folder_fin.begin(), folder_fin.end());

    // destination_file = file.c_str(); ==> v1.0.0
    // Folder Name + Save the source code from the website home page

    // URLDownloadToFile function
    if (S_OK == URLDownloadToFile(NULL, website_wide_L.c_str(),file.c_str(), 0, NULL))
    {
        cout << "Source Code saved in the same " << folder_init << ".txt\n";
        file_location(argv[0]);

        // v1.0.0
        // destination_file = NULL; ==> v1.0.0
        // website_url_L = NULL; ==> v1.0.0
        // v1.0.0
    }
    else if(SUCCEEDED(E_OUTOFMEMORY))
    {
        cout << "Out of memory\n";
        return EXIT_FAILURE;
    }
    else 
    {
        cout << "Invalid Website\n";
    }
    cout << "\nWould you like to continue?\nChoose from y/n\n";
    string options;
    cin >> options;
    if (options == "y") {
        cout << endl;
        website_url = "";
        folder_init = "";
        return main(argc,argv);
    }
    else if (options == "n")
        return EXIT_SUCCESS;
    else return EXIT_FAILURE;
}
/*
REQUIREMENTS
Minimum supported client

Windows XP

Minimum supported server

Windows 2000 Server
*/