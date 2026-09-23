#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    set<string> facts;
    vector<pair<string, string>> rules;
    vector<string> trace;
    string input, p, q, query;

    cout << "Masukkan fakta awal (ketik 'selesai' untuk lanjut):\n";
    while (true) {
        cout << "> ";
        cin >> input;
        if (input == "selesai") break;
        facts.insert(input);
    }

    cout << "\nMasukkan aturan implikasi (P -> Q).\n";
    cout << "(Ketik 'selesai' pada input P untuk lanjut)\n";
    while (true) {
        cout << "P (Antecedent): ";
        cin >> p;
        if (p == "selesai") break;
        cout << "Q (Consequent): ";
        cin >> q;
        rules.push_back({p, q});
    }

    cout << "\nMasukkan query yang ingin diuji: ";
    cin >> query;

    bool added = true;
    while (added) {
        added = false;
        for (auto& rule : rules) {
            if (facts.count(rule.first) && !facts.count(rule.second)) {
                facts.insert(rule.second);
                trace.push_back("Diketahui [" + rule.first + "] dan aturan [" + rule.first + " -> " + rule.second + "], maka [" + rule.second + "] disimpulkan.");
                added = true;
            }
        }
    }

    cout << "\n HASIL INFERENSI \n";
    if (facts.count(query)) {
        cout << "Kesimpulan: Query [" << query << "] BERHASIL dibuktikan!\n\n";
        cout << "Jejak Inferensi:\n";
        if (trace.empty()) {
            cout << "Query [" << query << "] sudah merupakan fakta awal.\n";
        } else {
            for (size_t i = 0; i < trace.size(); i++) {
                cout << i + 1 << ". " << trace[i] << "\n";
            }
        }
    } else {
        cout << "Kesimpulan: Query [" << query << "] GAGAL dibuktikan dari fakta dan aturan yang ada.\n";
    }

    return 0;
}