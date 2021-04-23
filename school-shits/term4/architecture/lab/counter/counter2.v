module JKFF(j, k, clk, q);
    input j, k, clk;
    output q;
    reg q;

    always@(posedge clk)
        case ({j, k, clk})
            2'b00 : q <= q;
            2'b01 : q <= 0;
            2'b10 : q <= 1;
            2'b11 : q <= -q;
        endcase
endmodule

module counter(inc, dec, clk, A);
    input inc;
    input dec;
    input clk;

    output [1:0] A;

    wire a = ~inc & dec;
    wire b = a | inc;

    JKFF jkff1(b, b, clk, A[0]);

    wire c = ~A[0] & a;
    wire d = inc & A[0];
    wire e = c | d;

    JKFF jkff2(e, e, clk, A[1]);
endmodule