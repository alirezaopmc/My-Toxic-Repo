module FullAdder(a, b, cin, s, cout);
    input a;
    input b;
    input cin;

    output s;
    output cout;

    assign #4 s = a ^ b ^ cin;
    assign #4 cout = (a & b) | (b & cin) | (cin & a);
endmodule

module MUX_1bit(a, b, s, o);
    parameter N = 1;

    input [N-1:0] a;
    input [N-1:0] b;
    input s;

    output [N-1:0] o;

    assign #4 o = (s == 0) ? a : b;
endmodule

module MUX_3bit(a, b, s, o);
    parameter N = 3;

    input [N-1:0] a;
    input [N-1:0] b;
    input s;

    output [N-1:0] o;

    assign #4 o = (s == 0) ? a : b;
endmodule

module MUX_4bit(a, b, s, o);
    parameter N = 4;

    input [N-1:0] a;
    input [N-1:0] b;
    input s;

    output [N-1:0] o;

    assign #4 o = (s == 0) ? a : b;
endmodule

module MUX_6bit(a, b, s, o);
    parameter N = 6;

    input [N-1:0] a;
    input [N-1:0] b;
    input s;

    output [N-1:0] o;

    assign #4 o = (s == 0) ? a : b;
endmodule

module RippleCarryAdder_3bit(a, b, cin, s, cout);
    parameter N = 3;

    input [N-1:0] a;
    input [N-1:0] b;
    input cin;

    output [N-1:0] s;
    output cout;

    wire [N-1:0] carry;

    genvar i;
    generate
    for (i = 0; i < N; i = i + 1) begin: generate_RippleCarryAdder
        if (i == 0)
            FullAdder f(a[0], b[0], cin, s[0], carry[0]);
        else
            FullAdder f(a[i], b[i], carry[i-1], s[i], carry[i]);
    end
    assign cout = carry[N-1];
    endgenerate
endmodule

module RippleCarryAdder_4bit(a, b, cin, s, cout);
    parameter N = 4;

    input [N-1:0] a;
    input [N-1:0] b;
    input cin;

    output [N-1:0] s;
    output cout;

    wire [N-1:0] carry;

    genvar i;
    generate
    for (i = 0; i < N; i = i + 1) begin: generate_RippleCarryAdder
        if (i == 0)
            FullAdder f(a[0], b[0], cin, s[0], carry[0]);
        else
            FullAdder f(a[i], b[i], carry[i-1], s[i], carry[i]);
    end
    assign cout = carry[N-1];
    endgenerate
endmodule

module RippleCarryAdder_6bit(a, b, cin, s, cout);
    parameter N = 6;

    input [N-1:0] a;
    input [N-1:0] b;
    input cin;

    output [N-1:0] s;
    output cout;

    wire [N-1:0] carry;

    genvar i;
    generate
    for (i = 0; i < N; i = i + 1) begin: generate_RippleCarryAdder
        if (i == 0)
            FullAdder f(a[0], b[0], cin, s[0], carry[0]);
        else
            FullAdder f(a[i], b[i], carry[i-1], s[i], carry[i]);
    end
    assign cout = carry[N-1];
    endgenerate
endmodule

module CarrySelectAdder_16bit_3_3_6_4(a, b, cin, s, cout);
    parameter N = 16;
    parameter G = 4;
    
    input [N-1:0] a;
    input [N-1:0] b;
    input cin;

    output [N-1:0] s;
    output cout;

    wire [N-1:3] s_c0;
    wire [N-1:3] s_c1;

    wire [3:0] sel;
    wire [G-1:1] c_c0;
    wire [G-1:1] c_c1;

    // 3bit [2:0] first RCA
    RippleCarryAdder_3bit RCA0(
        .a(a[2:0]),
        .b(b[2:0]),
        .cin(cin),
        .s(s[2:0]),
        .cout(sel[0])
    );

    // 3bit [5:3] second RCA with no carry
    RippleCarryAdder_3bit RCA1_c0(
        .a(a[5:3]),
        .b(b[5:3]),
        .cin(0),
        .s(s_c0[5:3]),
        .cout(c_c0[0])
    );

    // 3bit [5:3] second RCA with carry
    RippleCarryAdder_3bit RCA1_c1(
        .a(a[5:3]),
        .b(b[5:3]),
        .cin(1),
        .s(s_c1[5:3]),
        .cout(c_c1[0])
    );

    // 4bit [9:6] third RCA with no carry
    RippleCarryAdder_4bit RCA2_c0(
        .a(a[9:6]),
        .b(b[9:6]),
        .cin(0),
        .s(s_c0[9:6]),
        .cout(c_c0[1])
    );

    // 4bit [9:6] third RCA with carry
    RippleCarryAdder_4bit RCA2_c1(
        .a(a[9:6]),
        .b(b[9:6]),
        .cin(1),
        .s(s_c1[9:6]),
        .cout(c_c1[1])
    );

    // 6bit [15:10] fourth RCA with no carry
    RippleCarryAdder_6bit RCA3_c0(
        .a(a[15:10]),
        .b(b[15:10]),
        .cin(0),
        .s(s_c0[15:10]),
        .cout(c_c0[2])
    );

    // 6bit [15:10] fourth RCA with carry
    RippleCarryAdder_6bit RCA3_c1(
        .a(a[15:10]),
        .b(b[15:10]),
        .cin(1),
        .s(s_c1[15:10]),
        .cout(c_c1[2])
    );

    MUX_3bit s_g0(s_c0[5:3], s_c1[5:3], sel[0], s[5:3]);
    MUX_1bit c_g0(c_c0[1], c_c1[1], sel[0], sel[1]);

    MUX_4bit s_g1(s_c0[9:6], s_c1[9:6], sel[1], s[9:6]);
    MUX_1bit c_g1(c_c0[2], c_c1[2], sel[1], sel[2]);

    MUX_6bit s_g2(s_c0[15:10], s_c1[15:10], sel[2], s[15:10]);
    MUX_1bit c_g2(c_c0[3], c_c1[3], sel[2], sel[3]);

    assign #4 cout = sel[3];
endmodule

module CarrySelectAdder_16bit_3_3_6_4_TB;
    parameter N = 16;
    reg [N-1:0] a;
    reg [N-1:0] b;
    reg cin;

    wire [N-1:0] s;
    wire cout;    

    CarrySelectAdder_16bit_3_3_6_4 CSLA(
        .a(a),
        .b(b),
        .cin(cin),
        .s(s),
        .cout(cout)
    );

    initial begin
        #50

        a = 14;
        b = 3;
        cin = 0;

        #50

        a = 14;
        b = 3;
        cin = 1;

        #50

        a = 2;
        b = 3;
        cin = 0;

        #50

        a = 2;
        b = 3;
        cin = 1;

        #50
        
        a = 5;
        b = 5;
        cin = 0;

        #50
        
        a = 5;
        b = 5;
        cin = 1;

        #50
        
        a = 0;
        b = 0;
        cin = 1;

        #50
        
        a = 2;
        b = 0;
        cin = 1;

        #50
        
        a = 15;
        b = 15;
        cin = 0;

        #50
        
        a = 15;
        b = 15;
        cin = 1;
    end
endmodule