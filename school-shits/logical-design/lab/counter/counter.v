// inspired from
// https://www.javatpoint.com/verilog-jk-flip-flop

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

module Counter(inc, dec, clk, A);
    input inc, dec, clk;
    output [3:0] A;
    
    wire a = ~inc & dec;
    wire b = a | inc;

    JKFF jkff1(b, b, clk, A[0]);
    
    wire c = ~A[0] & a;
    wire d = inc & A[0];
    wire e = c | d;

    JKFF jkff2(e, e, clk, A[1]);

    wire g = d & A[1];
    wire h = ~A[1] & c;
    wire i = g | h;

    JKFF jkff3(i, i, clk, A[2]);

    wire j = g & A[2];
    wire k = ~A[2] & h;
    wire l = j | k;

    JKFF jkff4(l, l, clk, A[3]);
endmodule

