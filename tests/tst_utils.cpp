/*
 * Copyright 2021 Marius Gripsgard <marius@ubports.com>
 * Copyright 2021 Robert Tari <robert@tari.in>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include <memory>

extern "C" {
    #include "utils.h"
}

class XdgCurrentDesktopUtilsTest : public ::testing::Test
{
public:
   XdgCurrentDesktopUtilsTest() {}

   void SetUp() {
       unsetenv("XDG_CURRENT_DESKTOP");
   }

   void TearDown() {
       unsetenv("XDG_CURRENT_DESKTOP");
   }
};

TEST_F(XdgCurrentDesktopUtilsTest, isLomiri)
{
    EXPECT_FALSE(ayatana_common_utils_is_lomiri());
    setenv("XDG_CURRENT_DESKTOP", "Lomiri", 1);
    EXPECT_TRUE(ayatana_common_utils_is_lomiri());
}

TEST_F(XdgCurrentDesktopUtilsTest, isGnome)
{
    EXPECT_FALSE(ayatana_common_utils_is_gnome());
    setenv("XDG_CURRENT_DESKTOP", "GNOME", 1);
    EXPECT_TRUE(ayatana_common_utils_is_gnome());
}
TEST_F(XdgCurrentDesktopUtilsTest, isUnity)
{
    EXPECT_FALSE(ayatana_common_utils_is_unity());
    setenv("XDG_CURRENT_DESKTOP", "Unity", 1);
    EXPECT_TRUE(ayatana_common_utils_is_unity());
}
TEST_F(XdgCurrentDesktopUtilsTest, isMate)
{
    EXPECT_FALSE(ayatana_common_utils_is_mate());
    setenv("XDG_CURRENT_DESKTOP", "MATE", 1);
    EXPECT_TRUE(ayatana_common_utils_is_mate());
}
TEST_F(XdgCurrentDesktopUtilsTest, isXfce)
{
    EXPECT_FALSE(ayatana_common_utils_is_xfce());
    setenv("XDG_CURRENT_DESKTOP", "XFCE", 1);
    EXPECT_TRUE(ayatana_common_utils_is_xfce());
}
TEST_F(XdgCurrentDesktopUtilsTest, isPantheon)
{
    EXPECT_FALSE(ayatana_common_utils_is_pantheon());
    setenv("XDG_CURRENT_DESKTOP", "PANTHEON", 1);
    EXPECT_TRUE(ayatana_common_utils_is_pantheon());
}
TEST_F(XdgCurrentDesktopUtilsTest, isBudgie)
{
    EXPECT_FALSE(ayatana_common_utils_is_budgie());
    setenv("XDG_CURRENT_DESKTOP", "Budgie:GNOME", 1);
    EXPECT_TRUE(ayatana_common_utils_is_budgie());
}

class StringFunctionsTest : public ::testing::Test
{
public:

    StringFunctionsTest()
    {
    }

    void SetUp()
    {
        GSettingsSchemaSource *pSource = g_settings_schema_source_get_default();

        if (pSource != NULL)
        {
            GSettingsSchema *pSchema = g_settings_schema_source_lookup(pSource, "org.ayatana.common", FALSE);

            if (pSchema != NULL)
            {
                g_settings_schema_unref(pSchema);
                this->pSettings = g_settings_new("org.ayatana.common");
                this->nMaxLetters = g_settings_get_uint(pSettings, "max-menu-text-length");
                g_settings_set_uint(this->pSettings, "max-menu-text-length", 50);
            }
        }
    }

    void TearDown()
    {
        if (this->pSettings != NULL)
        {
            g_settings_set_uint(pSettings, "max-menu-text-length", this->nMaxLetters);
            g_object_unref(this->pSettings);
        }
    }

private:

    GSettings *pSettings;
    guint nMaxLetters;
};

TEST_F(StringFunctionsTest, elipsize)
{
    gchar *sTest1 = g_strdup("öüóőúéáűšđß");
    ayatana_common_utils_elipsize((gchar*)sTest1);
    EXPECT_STREQ(sTest1, "öüóőúéáűšđß");

    gchar *sTest2 = g_strdup("123456789012345678901234567890123456789012345öüóőúéáűšđß");
    ayatana_common_utils_elipsize((gchar*)sTest2);
    EXPECT_STREQ(sTest2, "123456789012345678901234567890123456789012345öüóőú...");
}
