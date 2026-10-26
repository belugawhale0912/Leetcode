// helper function to get value
int getValue(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

int romanToInt(char* s) {

    int output = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int current = getValue(s[i]);
        int next = getValue(s[i + 1]);

        if (next > current) { // if next value is bugger than current value (e.g. : IV, 'V' is greater than 'I')
            output += (next - current); // subtract to get values like IV which is 5 - 1 = 4
            i++; // increment counter by 1 as we processed two character
        } else {
            output += current;
        }
    }

    return output;
}