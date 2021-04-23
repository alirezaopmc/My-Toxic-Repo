module FullAdder(a, b, cin, s, cout);
    input a;
    input b;
    input cin;

    output s;
    output cout;

    assign s = a ^ b ^ cin;
    assign cout = (a & b) | (b & cin) | (cin & a);
endmodule

module RippleCarryAdder(a, b, cin, s, cout, N);
    parameter N;

    input [N-1:0] a;
    input [N-1:0] b;
    input cin;

    output [N-1:0] s;
    output cout;

    wire [N-1:0] carry;

    genvar i;
    generate
    for (i = 0; i < N; i = i + 1) begin
        if (i == 0)
            FullAdder f(a[0], b[0], cin, s[0], carry[0]);
        else
            FullAdder f(a[i], b[i], carry[i-1], s[i], carry[i]);
    end

    assign cout = carry[N-1];
    endgenerate
endmodule

module CarrySelectAdder(a, b, cin, s, cout, N, groups, G);
    parameter N;
    parameter G;
    
    input [N-1:0] a;
    input [N-1:0] b;
    input cin;

    output [N-1:0] s;
    output cout;

    