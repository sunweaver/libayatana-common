/*
 * Copyright 2021 Marius Gripsgard <marius@ubports.com>
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
    EXPECT_FALSE(is_lomiri());
    setenv("XDG_CURRENT_DESKTOP", "Lomiri", 1);
    EXPECT_TRUE(is_lomiri());
}

TEST_F(XdgCurrentDesktopUtilsTest, isGnome)
{
    EXPECT_FALSE(is_gnome());
    setenv("XDG_CURRENT_DESKTOP", "GNOME", 1);
    EXPECT_TRUE(is_gnome());
}
TEST_F(XdgCurrentDesktopUtilsTest, isUnity)
{
    EXPECT_FALSE(is_unity());
    setenv("XDG_CURRENT_DESKTOP", "Unity", 1);
    EXPECT_TRUE(is_unity());
}
TEST_F(XdgCurrentDesktopUtilsTest, isMate)
{
    EXPECT_FALSE(is_mate());
    setenv("XDG_CURRENT_DESKTOP", "MATE", 1);
    EXPECT_TRUE(is_mate());
}
TEST_F(XdgCurrentDesktopUtilsTest, isXfce)
{
    EXPECT_FALSE(is_xfce());
    setenv("XDG_CURRENT_DESKTOP", "XFCE", 1);
    EXPECT_TRUE(is_xfce());
}
TEST_F(XdgCurrentDesktopUtilsTest, isPantheon)
{
    EXPECT_FALSE(is_pantheon());
    setenv("XDG_CURRENT_DESKTOP", "PANTHEON", 1);
    EXPECT_TRUE(is_pantheon());
}
TEST_F(XdgCurrentDesktopUtilsTest, isBudgie)
{
    EXPECT_FALSE(is_budgie());
    setenv("XDG_CURRENT_DESKTOP", "Budgie:GNOME", 1);
    EXPECT_TRUE(is_budgie());
}
