#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{};

TEST_F(SoundexTests, check_if_one_letter_will_be_encrypt_correctly)
{
    Soundex soundex("B");
    ASSERT_EQ("B000", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_two_letters_will_be_encrypt_correctly)
{
    Soundex soundex("Bn");
    ASSERT_EQ("B500", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_three_letters_will_be_encrypt_correctly)
{
    Soundex soundex("Btl");
    ASSERT_EQ("B340", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_four_letters_will_be_encrypt_correctly)
{
    Soundex soundex("Bttl");
    ASSERT_EQ("B340", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_Robert_will_be_encrypt_to_R163)
{
    Soundex soundex("Robert");
    ASSERT_EQ("R163", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_Rupert_will_be_encrypt_to_R163)
{
    Soundex soundex("Rupert");
    ASSERT_EQ("R163", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_Rubin_will_be_encrypt_to_R150)
{
    Soundex soundex("Rubin");
    ASSERT_EQ("R150", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_Ashcraft_will_be_encrypt_to_A261)
{
    Soundex soundex("Ashcraft");
    ASSERT_EQ("A261", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_Ashcroft_will_be_encrypt_to_A261)
{
    Soundex soundex("Ashcroft");
    ASSERT_EQ("A261", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_Tymczak_will_be_encrypt_to_T522)
{
    Soundex soundex("Tymczak");
    ASSERT_EQ("T522", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_Pfister_will_be_encrypt_to_P236)
{
    Soundex soundex("Pfister");
    ASSERT_EQ("P236", soundex.encrypt());
}

TEST_F(SoundexTests, check_if_Honeyman_will_be_encrypt_to_H555)
{
    Soundex soundex("Honeyman");
    ASSERT_EQ("H555", soundex.encrypt());
}

