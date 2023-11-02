#include <bits/stdc++.h>
using namespace std;


unordered_map<string, uint16_t> signals;
unordered_map<string, vector<string>> gates;

uint16_t get_signal(string wire) {
    

    if (signals.find(wire) != signals.end())
        return signals[wire];

    vector<string> gate = gates[wire];
    string op = gate[0];

    if (op == "NOT")
        signals[wire] = ~get_signal(gate[1]);
    else if (op == "AND")
        signals[wire] = get_signal(gate[1]) & get_signal(gate[2]);
    else if (op == "OR")
        signals[wire] = get_signal(gate[1]) | get_signal(gate[2]);
    else if (op == "LSHIFT")
        signals[wire] = (get_signal(gate[1]) << stoi(gate[2]));
    else if (op == "RSHIFT")
        signals[wire] = get_signal(gate[1]) >> stoi(gate[2]);

    return signals[wire];
}

int main() {
    ifstream file("input.in");
    string line;
    
    while (getline(file, line)) {
        istringstream iss(line);
        string gate_str, wire;
        iss >> gate_str >> wire;
        // string gate_str, wire1, wire2, dest, arrow;
        // iss >> wire1 >> gate_str >> wire2 >> arrow >> dest;


        if (gate_str == "NOT") {
            string dest;
            iss >> dest;
            gates[wire] = { gate_str, dest };
        }
        else if (gate_str == "AND" || gate_str == "OR" || gate_str == "LSHIFT" || gate_str == "RSHIFT") {
            string input1, arrow, input2, dest;
            // iss >> input1 >> arrow >> input2;
           iss >> input1 >> gate_str >> input2 >> arrow >> dest; 
            gates[wire] = { gate_str, input1, input2 };
        }
        else {
            uint16_t value = stoi(gate_str);
            signals[wire] = value;
        }
    }

    uint16_t signal_to_a = get_signal("a");
    cout << "wire a: " << signal_to_a << endl;

    return 0;
}
