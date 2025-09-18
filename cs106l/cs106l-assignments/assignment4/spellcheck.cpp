#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  // 获取空格所在位置的迭代器，以及收尾两个迭代器
  auto vec = find_all(source.begin(), source.end(), isspace);

  // 创建一个空的集合
  Corpus tokens;

  // 构造tokens插入集合
  std::transform(vec.begin(), vec.end()-1, vec.begin()+1, 
                      std::inserter(tokens, tokens.begin()),
                      [&source](auto it1, auto it2){
                      return Token{source, it1, it2};
  });
  std::erase_if(tokens, [](Token token){
    return token.content.empty();
  });

  return tokens;
}

namespace rv = std::ranges::views;
std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */

  auto view = source 
  | rv::filter(
    [&dictionary](Token token){
      return !dictionary.contains(token.content);
    }
  )
  | rv::transform(
    [&dictionary](Token token) -> Misspelling {
      auto oneDistance = dictionary | rv::filter([&token](std::string str){
        return levenshtein(str, token.content) == 1;
      });
      std::set<std::string> suggestions(oneDistance.begin(), oneDistance.end());
      return Misspelling{token, suggestions};
    }
  )
  | rv::filter(
    [](Misspelling misspelling){
      return !misspelling.suggestions.empty();
    }
  );
  std::set<Misspelling> ispell(view.begin(), view.end());
  return ispell;
};

/* Helper methods */

#include "utils.cpp"