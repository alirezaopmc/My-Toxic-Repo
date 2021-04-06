
module SixteenBitAdder(a, b, c, sum, carry);
    input [15:0] a;
    input [15:0] b;
    input c;
    output [15:0] sum;
    output carry;
    wire carry_block_01;
    wire carry_block_12;
    wire carry_block_23;
endmodule

module SixteenBitAdderTest;
    reg [15:0] a;
    reg [15:0] b;
    reg c;
    wire [15:0] sum;
    wire carry;

    FourBitAdder bit_1 (
        .a(a[3:0]),
        .b(b[3:0]),
        .c(0),
        .sum(sum[3:0]),
        .carry(carry_block_01)
    );

    FourBitAdder bit_2 (
        .a(a[7:4]),
        .b(b[7:4]),
        .c(carry_block_01),
        .sum(sum[7:4]),
        .carry(carry_block_12)
    );

    FourBitAdder bit_3 (
        .a(a[11:8]),
        .b(b[11:8]),
        .c(carry_block_12),
        .sum(sum[11:8]),
        .carry(carry_block_23)
    );

    FourBitAdder bit_4 (
        .a(a[15:12]),
        .b(b[15:12]),
        .c(carry_block_23),
        .sum(sum[15:12]),
        .carry(carry)
    );

    initial begin
        a = 16'd30;
        b = 16'd12;
        c = 1'b0;

        #50

        a = 16'd30;
        b = 16'd12;
        c = 1'b0;

        #50

        a = 16'd41;
        b = 16'd2;
        c = 1'b0;

        #50

        a = 16'd10;
        b = 16'd16;
        c = 1'b1;
    end
endmodule

