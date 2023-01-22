//
// Created by chloe on 8/01/2023.
//

#include "..\include\catch2\catch.hpp"
#include "..\include\BloomFilter.h"

TEST_CASE("Usernames") {
    std::size_t bit_size = 50;
    std::vector<std::size_t> v;

    // 3 constants for 3 different hashing functions
    v.push_back(10); v.push_back(55); v.push_back(36);

    // creates BloomFilter1
    BloomFilter<std::string> BloomFilter1(bit_size, v);

    // insert all of the usernames
    BloomFilter1.insert("artemlover675");
    BloomFilter1.insert("het_mike");
    BloomFilter1.insert("WikiTheWikipedia");
    BloomFilter1.insert("LesPleiades");
    BloomFilter1.insert("ganyuandmikasalover002");
    BloomFilter1.insert("RedKatana");
    BloomFilter1.insert("Ouzen");
    BloomFilter1.insert("wardabest");
    BloomFilter1.insert("jungkooklover256");
    BloomFilter1.insert("Alt");

    CHECK(BloomFilter1.query("artemlover675") == 1);
    CHECK(BloomFilter1.query("het_mike") == 1);
    CHECK(BloomFilter1.query("notsure") == 0);
    CHECK(BloomFilter1.query("Banzai") == 0);                   // is a false positive !!!
    CHECK(BloomFilter1.query("EmbeddedIn[Darkness]") == 0);     // is a false positive !!!


    CHECK(BloomFilter1.is_full()==0);                                  // is clearly not full yet

}
