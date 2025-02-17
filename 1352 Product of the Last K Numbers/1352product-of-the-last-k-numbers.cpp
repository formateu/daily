#pragma once

class ProductOfNumbers {
  private:
      std::vector<int> prefixProd;
  public:
      ProductOfNumbers() {
          
      }
      
      void add(int num) {
          if (prefixProd.empty() && num != 0) {
              prefixProd.emplace_back(num);
          } else {
              if (num == 0) {
                  prefixProd.clear();
              } else  {
                  const auto &last = prefixProd.back();
                  prefixProd.emplace_back(last*num);
              }
          }
      }
      
      int getProduct(int k) {
          if (prefixProd.empty() || prefixProd.size() < static_cast<std::size_t>(k)) {
              return 0;
          } else if (prefixProd.size() == k) {
            return prefixProd.back();
          }
      
          auto first = prefixProd.rbegin();
          auto end = first + k;
          return *first / *end; 
      }
  };
  
  /**
   * Your ProductOfNumbers object will be instantiated and called as such:
   * ProductOfNumbers* obj = new ProductOfNumbers();
   * obj->add(num);
   * int param_2 = obj->getProduct(k);
   */