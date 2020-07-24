/*
 DO NOT EDIT MANUALLY !!!
 Generated by scripts\trans_gen.py
*/

#include "BaseUtil.h"

namespace trans {

#define LANGS_COUNT   1
#define STRINGS_COUNT 43

const char *gOriginalStrings[STRINGS_COUNT] = {
  "&Options",
  "Are you sure you want to uninstall SumatraPDF?",
  "Close",
  "Couldn't create temporary directory",
  "Couldn't create the installation directory",
  "Couldn't install PDF previewer",
  "Couldn't install PDF search filter",
  "Couldn't install browser plugin",
  "Couldn't obtain temporary directory",
  "Couldn't remove installation directory",
  "Couldn't remove the shortcut",
  "Couldn't uninstall PDF previewer",
  "Couldn't uninstall PDF search filter",
  "Couldn't uninstall browser plugin",
  "Couldn't write %s to disk",
  "Failed to copy uninstaller to temp directory",
  "Failed to create a shortcut",
  "Failed to delete uninstaller registry keys",
  "Failed to write the extended file extension information to the registry",
  "Failed to write the uninstallation information to the registry",
  "Hide &Options",
  "Install PDF &browser plugin for Firefox, Chrome and Opera",
  "Install SumatraPDF",
  "Install SumatraPDF in &folder:",
  "Installation failed!",
  "Installation in progress...",
  "Let Windows Desktop Search &search PDF documents",
  "Let Windows show &previews of PDF documents",
  "Please close %s to proceed!",
  "Select the folder where SumatraPDF should be installed:",
  "Some files to be installed are damaged or missing",
  "Start SumatraPDF",
  "SumatraPDF %s Installer",
  "SumatraPDF %s Uninstaller",
  "SumatraPDF has been uninstalled.",
  "SumatraPDF installation not found.",
  "Thank you for choosing SumatraPDF!",
  "Thank you! SumatraPDF has been installed.",
  "The installer has been corrupted. Please download it again.\nSorry for the inconvenience!",
  "Uninstall SumatraPDF",
  "Uninstallation failed",
  "Uninstallation in progress...",
  "Use SumatraPDF as the &default PDF reader"
};

const char **GetOriginalStrings() { return &gOriginalStrings[0]; }




static const char *gTranslations[LANGS_COUNT] = {
  NULL,

};

const char *GetTranslationsForLang(int langIdx) { return gTranslations[langIdx]; }


const char *gLangCodes =   "en\0" "\0";

const char *gLangNames =   "English\0" "\0";

// from http://msdn.microsoft.com/en-us/library/windows/desktop/dd318693(v=vs.85).aspx
// those definition are not present in 7.0A SDK my VS 2010 uses
#ifndef LANG_CENTRAL_KURDISH
#define LANG_CENTRAL_KURDISH 0x92
#endif

#ifndef SUBLANG_CENTRAL_KURDISH_CENTRAL_KURDISH_IRAQ
#define SUBLANG_CENTRAL_KURDISH_CENTRAL_KURDISH_IRAQ 0x01
#endif

#define _LANGID(lang) MAKELANGID(lang, SUBLANG_NEUTRAL)
const LANGID gLangIds[LANGS_COUNT] = {
  _LANGID(LANG_ENGLISH)
};
#undef _LANGID

bool IsLangRtl(int idx)
{
  return false;
}

int gLangsCount = LANGS_COUNT;
int gStringsCount = STRINGS_COUNT;

const LANGID *GetLangIds() { return &gLangIds[0]; }

} // namespace trans
