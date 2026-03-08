#include <iostream>
#include <string>
#include <unordered_map> // 해시 맵을 쓰기 위해 꼭 필요해!
using namespace std;
int main() {
    // 1. 선언: <키의 타입, 값의 타입> 순서로 적어줘.
    unordered_map<string, int> inventory;

    // 2. 데이터 추가
    inventory["Apple"] = 500;             // 가장 직관적인 방법
    inventory.insert({"Banana", 300});    // insert 함수 사용
    inventory.emplace("Orange", 200);     // 성능상 조금 더 유리한 방법

    // 3. 데이터 탐색
    string item = "Apple";
    if (inventory.find(item) != inventory.end()) {
        cout << item << "의 가격: " << inventory[item] << "원" << std::endl;
    } else {
        cout << "항목을 찾을 수 없어!" << std::endl;
    }

    // 4. 데이터 삭제
    inventory.erase("Banana");

    // 5. 전체 순회 (C++11 이상 범위 기반 루프)
    std::cout << "\n--- 현재 재고 목록 ---" << std::endl;
    for (const auto& pair : inventory) {
        // pair.first는 Key, pair.second는 Value야.
        std::cout << pair.first << ": " << pair.second << "원" << std::endl;
    }

    return 0;
}