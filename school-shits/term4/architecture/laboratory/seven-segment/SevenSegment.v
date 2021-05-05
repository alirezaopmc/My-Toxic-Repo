module SevenSegment(a, p);
    // Input bits for a number
    input [4-1:0] a;
    
    // Output bits for seven segments
    output [7-1:0] p;
    
    // ===== Implementation =====
    case (a)
        4'b0000: p = 7'b0000001; // 0
        4'b0001: p = 7'b1001111; // 1
        4'b0010: p = 7'b0010010; // 2
        4'b0011: p = 7'b0000110; // 3
        4'b0100: p = 7'b1001100; // 4
        4'b0101: p = 7'b0100100; // 5
        4'b0110: p = 7'b0100000; // 6
        4'b0111: p = 7'b0001111; // 7
        4'b1000: p = 7'b0000001; // 8
        4'b1001: p = 7'b0000001; // 9
        4'b1010: p = 7'b0000001; // A
        4'b1011: p = 7'b0000001; // b
        4'b1100: p = 7'b0000001; // C
        4'b1101: p = 7'b0000001; // d
        4'b1110: p = 7'b0000001; // E
        4'b1111: p = 7'b0000001; // F
        default: 
    endcase

