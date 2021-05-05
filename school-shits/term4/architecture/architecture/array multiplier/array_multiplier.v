// Help me with generate :| why??!




module FullAdder(a, b, cin, s, cout);
    input a;
    input b;
    input cin;

    output s;
    output cout;

    assign #4 cout = (a & b) | (b & cin) | (cin & a);
    assign #3 s = a ^ b ^ cin;
endmodule

module HalfAdder (a, b, s, cout);
    input a;
    input b;

    output s;
    output cout;

    assign #2 cout = a ^ b;
    assign #1 s = a & b;
endmodule

// module ArrayMultiplier_6x6(a, b, s);
//     parameter N = 6;

//     input [N-1:0] a;
//     input [N-1:0] b;

//     output [2*N-1:0] s;

//     wire [31-1:0] ac; // adder cout
//     wire [30-1:0] as; // adder sum 

//     assign s[0] = a[0] & b[0];

//     HalfAdder ha_0(
//         .a(a[1] & b[0]),
//         .b(a[0] & b[1]),
//         .s(as[0]),
//         .cout(ac[0])
//     );

//     FullAdder fa_1(
//         .a(a[2] & b[0]),
//         .b(a[1] & b[1]),
//         .cin(ac[0]),
//         .s(as[1]),
//         .cout(ac[1])
//     );

//     FullAdder fa_3(
//         .a(a[3] & b[0]),
//         .b(a[2] & b[1]),
//         .cin(ac[1]),
//         .s(as[3]),
//         .cout(ac[3])
//     );

//     FullAdder fa_6(
//         .a(a[4] & b[0]),
//         .b(a[3] & b[1]),
//         .cin(ac[3]),
//         .s(as[6]),
//         .cout(ac[6])
//     );

//     FullAdder fa_10(
//         .a(a[5] & b[0]),
//         .b(a[4] & b[1]),
//         .cin(ac[6]),
//         .s(as[10]),
//         .cout(ac[10])
//     );

//     HalfAdder ha_2(
//         .a(a[0] & b[2]),
//         .b(as[1]),
//         .s(as[2]),
//         .cout(ac[2])
//     );

//     FullAdder fa_4(
//         .a(a[1] & b[2]),
//         .b(as[3]),
//         .cin(ac[2]),
//         .s(as[4]),
//         .cout(ac[4])
//     );

//     FullAdder fa_7(
//         .a(a[2] & b[2]),
//         .b(as[6]),
//         .cin(ac[4]),
//         .s(as[8]),
//         .cout(ac[8])
//     );

//     FullAdder fa_11(
//         .a(a[3] & b[2]),
//         .b(as[10]),
//         .cin(ac[7]),
//         .s(as[11]),
//         .cout(ac[11])
//     );

//     FullAdder fa_15(
//         .a(a[5] & b[1]),
//         .b(ac[10]),
//         .cin(ac[11]),
//         .s(as[15]),
//         .cout(ac[15])
//     );

//     HalfAdder ha_5(
//         .a(a[0] & b[3]),
//         .b(as[4]),
//         .s(as[5]),
//         .cout(ac[5])
//     );

//     FullAdder fa_8(
//         .a(a[1] & b[3]),
//         .b(as[7]),
//         .cin(ac[5]),
//         .s(as[8]),
//         .cout(ac[8])
//     );

//     FullAdder fa_12(
//         .a(a[2] & b[3]),
//         .b(as[11]),
//         .cin(ac[8]),
//         .s(as[12]),
//         .cout(ac[12])
//     );

//     FullAdder fa_16(
//         .a(a[4] & b[2]),
//         .b(as[15]),
//         .cin(ac[12]),
//         .s(as[16]),
//         .cout(ac[16])
//     );

//     FullAdder fa_20(
//         .a(a[5] & b[2]),
//         .b(ac[15]),
//         .cin(ac[16]),
//         .s(as[20]),
//         .cout(ac[20])
//     );

//     HalfAdder ha_9(
//         .a(a[0] & b[4]),
//         .b(as[8]),
//         .s(as[9]),
//         .cout(ac[9])
//     );

//     FullAdder fa_13(
//         .a(a[1] & b[4]),
//         .b(a[1] & b[1]),
//         .cin(ac[9]),
//         .s(as[13]),
//         .cout(ac[13])
//     );

//     FullAdder fa_17(
//         .a(a[3] & b[3]),
//         .b(as[16]),
//         .cin(ac[13]),
//         .s(as[17]),
//         .cout(ac[17])
//     );

//     FullAdder fa_21(
//         .a(a[4] & b[3]),
//         .b(as[20]),
//         .cin(ac[17]),
//         .s(as[21]),
//         .cout(ac[21])
//     );

//     FullAdder fa_24(
//         .a(a[5] & b[3]),
//         .b(ac[20]),
//         .cin(ac[21]),
//         .s(as[24]),
//         .cout(ac[24])
//     );

//     HalfAdder ha_14(
//         .a(a[0] & b[5]),
//         .b(as[13]),
//         .s(as[14]),
//         .cout(ac[14])
//     );

//     FullAdder fa_18(
//         .a(a[2] & b[4]),
//         .b(as[17]),
//         .cin(ac[14]),
//         .s(as[18]),
//         .cout(ac[18])
//     );

//     FullAdder fa_22(
//         .a(a[3] & b[4]),
//         .b(as[21]),
//         .cin(ac[18]),
//         .s(as[22]),
//         .cout(ac[22])
//     );

//     FullAdder fa_25(
//         .a(a[4] & b[4]),
//         .b(a[1] & b[1]),
//         .cin(ac[22]),
//         .s(as[25]),
//         .cout(ac[25])
//     );

//     FullAdder fa_27(
//         .a(a[5] & b[4]),
//         .b(ac[24]),
//         .cin(ac[25]),
//         .s(as[27]),
//         .cout(ac[27])
//     );

//     HalfAdder ha_19(
//         .a(a[1] & b[5]),
//         .b(as[18]),
//         .s(as[19]),
//         .cout(ac[19])
//     );

//     FullAdder fa_23(
//         .a(a[2] & b[5]),
//         .b(as[22]),
//         .cin(ac[19]),
//         .s(as[23]),
//         .cout(ac[23])
//     );

//     FullAdder fa_26(
//         .a(a[3] & b[5]),
//         .b(as[25]),
//         .cin(ac[23]),
//         .s(as[26]),
//         .cout(ac[26])
//     );

//     FullAdder fa_28(
//         .a(a[4] & b[5]),
//         .b(as[28]),
//         .cin(ac[26]),
//         .s(as[28]),
//         .cout(ac[28])
//     );

//     FullAdder fa_29(
//         .a(a[5] & b[5]),
//         .b(ac[27]),
//         .cin(ac[28]),
//         .s(as[29]),
//         .cout(ac[29])
//     );

//     assign s[1] = as[0];
//     assign s[2] = as[2];
//     assign s[3] = as[5];
//     assign s[4] = as[9];
//     assign s[5] = as[14];
//     assign s[6] = as[19];
//     assign s[7] = as[23];
//     assign s[8] = as[26];
//     assign s[9] = as[28];
//     assign s[10] = as[29];
//     assign s[11] = ac[30];
// endmodule


// module ArrayMultiplier_6x6_TB;
//     parameter N = 6;

//     reg [N-1:0] a;
//     reg [N-1:0] b;

//     wire [2*N-1:0] s;

//     localparam p = 100;

//     ArrayMultiplier_6x6 am(a, b, s);

//     initial begin
//         a = 0;
//         b = 1;
//         #p;

//         a = 2;
//         b = 2;
//         #p;
//     end
// endmodule

module ArrayMultiplier_6x6(A, B, S);
    parameter N = 6;
    parameter M = 6;

    input [N-1:0] A;
    input [M-1:0] B;

    output [N+M-1:0] S;

    wire [N*(M-1):0] cell_c; // Cell Carry
    wire [N*(M-1):0] cell_s; // Cell Sum
    
    HalfAdder cell_0(A[0] & B[1], A[1] & B[0], cell_s[0], cell_c[0]);
    HalfAdder cell_1(A[0] & B[2], A[1] & B[1], cell_s[1], cell_c[1]);
    HalfAdder cell_2(A[0] & B[3], A[1] & B[2], cell_s[2], cell_c[2]);
    HalfAdder cell_3(A[0] & B[4], A[1] & B[3], cell_s[3], cell_c[3]);
    HalfAdder cell_4(A[0] & B[5], A[1] & B[4], cell_s[4], cell_c[4]);
    
    FullAdder cell_5(A[2] & B[0], cell_s[1], cell_c[0], cell_s[5], cell_c[5]);
    FullAdder cell_6(A[2] & B[1], cell_s[2], cell_c[1], cell_s[6], cell_c[6]);
    FullAdder cell_7(A[2] & B[2], cell_s[3], cell_c[2], cell_s[7], cell_c[7]);
    FullAdder cell_8(A[2] & B[3], cell_s[4], cell_c[3], cell_s[8], cell_c[8]);
    FullAdder cell_9(A[2] & B[4], A[1] & B[5], cell_c[4], cell_s[9], cell_c[9]);
    
    FullAdder cell_10(A[3] & B[0], cell_s[6], cell_c[5], cell_s[10], cell_c[10]);
    FullAdder cell_11(A[3] & B[1], cell_s[7], cell_c[6], cell_s[11], cell_c[11]);
    FullAdder cell_12(A[3] & B[2], cell_s[8], cell_c[7], cell_s[12], cell_c[12]);
    FullAdder cell_13(A[3] & B[3], cell_s[9], cell_c[8], cell_s[13], cell_c[13]);
    FullAdder cell_14(A[3] & B[4], A[2] & B[5], cell_c[9], cell_s[14], cell_c[14]);
    
    FullAdder cell_15(A[4] & B[0], cell_s[11], cell_c[10], cell_s[15], cell_c[15]);
    FullAdder cell_16(A[4] & B[1], cell_s[12], cell_c[11], cell_s[16], cell_c[16]);
    FullAdder cell_17(A[4] & B[2], cell_s[13], cell_c[12], cell_s[17], cell_c[17]);
    FullAdder cell_18(A[4] & B[3], cell_s[14], cell_c[13], cell_s[18], cell_c[18]);
    FullAdder cell_19(A[4] & B[4], A[3] & B[5], cell_c[14], cell_s[19], cell_c[19]);
    
    FullAdder cell_20(A[5] & B[0], cell_s[16], cell_c[15], cell_s[20], cell_c[20]);
    FullAdder cell_21(A[5] & B[1], cell_s[17], cell_c[16], cell_s[21], cell_c[21]);
    FullAdder cell_22(A[5] & B[2], cell_s[18], cell_c[17], cell_s[22], cell_c[22]);
    FullAdder cell_23(A[5] & B[3], cell_s[19], cell_c[18], cell_s[23], cell_c[23]);
    FullAdder cell_24(A[5] & B[4], A[4] & B[5], cell_c[19], cell_s[24], cell_c[24]);
    
    HalfAdder cell_25(cell_s[20], cell_s[21], cell_s[25], cell_c[25]);
    FullAdder cell_26(cell_s[21], cell_s[22], cell_c[21], cell_s[26], cell_c[26]);
    FullAdder cell_27(cell_s[22], cell_s[23], cell_c[22], cell_s[27], cell_c[27]);
    FullAdder cell_28(cell_s[23], cell_s[24], cell_c[23], cell_s[28], cell_c[28]);
    FullAdder cell_29(cell_s[24], A[5] & B[5], cell_c[28], cell_s[29], cell_c[29]);
    
    assign S[0] = A[0] & B[0];
    assign S[1] = cell_s[0];
    assign S[2] = cell_s[5];
    assign S[3] = cell_s[10];
    assign S[4] = cell_s[15];
    assign S[5] = cell_s[20];
    assign S[6] = cell_s[25];
    assign S[7] = cell_s[26];
    assign S[8] = cell_s[27];
    assign S[9] = cell_s[28];
    assign S[10] = cell_s[29];
    assign S[11] = cell_c[29];

    // genvar j;
    // // First Row
    // generate
    //     for (j = 0; j < M-1; j = j + 1) begin
    //         HalfAdder first(
    //             .a(A[0] & B[j+1]),
    //             .b(A[1] & B[j]),
    //             .s(cell_s[j]),
    //             .cout(cell_c[j])
    //         );
    //     end
    // endgenerate

    // genvar r;
    // // Middle Rows
    // generate
    //     // for(r = M; r < N - 1; r = r + 1) begin
    //     //     for(j = 1; j < M; j = j + 1) begin
    //     //         if (j == M-1) begin
    //     //             FullAdder middle(
    //     //                 .a(A[r+1] & B[j-1]),
    //     //                 .b(A[r] & B[M-1]),
    //     //                 .cin(cell_c[r * (M - 1) + j - 1 - (M - 1)]),
    //     //                 .s(cell_s[r * (M - 1) + j - 1]),
    //     //                 .cout(cell_c[r * (M - 1) + j - 1])
    //     //             );
    //     //         end else begin
    //     //             FullAdder middle(
    //     //                 .a(A[r+1] & B[j-1]),
    //     //                 .b(cell_s[r * (M - 1) + j - 1 - (M - 1) + 1]),
    //     //                 .cin(cell_c[r * (M - 1) + j - 1 - (M - 1)]),
    //     //                 .s(cell_s[r * (M - 1) + j - 1]),
    //     //                 .cout(cell_c[r * (M - 1) + j - 1])
    //     //             );
    //     //         end
    //     //     end
    //     // end

    //     for(r = M; r < N*(M-1)-(M-1); r = r + 1) begin
    //         if (r % (M-1) == 4) begin
    //             FullAdder middle(
    //                 .a(A[(r + (M-1)) / 5] & B[r % (M-1)]),
    //                 .b(cell_c[r - (M-1)]),
    //                 .cin(cell_s[r - (M-1) + 1]),
    //                 .s(cell_s[r]),
    //                 .cout(cell_c[r])
    //             );
    //         end
    //     end
    // endgenerate

    // // Last Row
    // generate
    //     for(r = (N-1) * (M-1); r < N * (M-1); r = r + 1) begin
    //         if (r == (N-1) * (M-1)) begin
    //             HalfAdder last(
    //                 .a(cell_s[r - (M-1)]),
    //                 .b(cell_c[r - (M-1) + 1]),
    //                 .s(cell_s[r]),
    //                 .cout(cell_c[r])
    //             );
    //         end else if (r == N * (M-1) - 1) begin
    //             FullAdder last(
    //                 .a(A[N-1] & B[M-1]),
    //                 .b(cell_s[r - (M-1)]),
    //                 .cin(cell_c[r-1]),
    //                 .s(cell_s[r]),
    //                 .cout(cell_c[r])
    //             );
    //         end else begin
    //             FullAdder last(
    //                 .a(cell_s[r - (M-1)] + 1),
    //                 .b(cell_s[r - (M-1)]),
    //                 .cin(cell_c[r-1]),
    //                 .s(cell_s[r]),
    //                 .cout(cell_c[r])
    //             );
    //         end
    //     end
    // endgenerate

    // assign S[0] = A[0] & B[0];

    // genvar i;
    // generate
    //     for(i = 0; i < N - 1; i = i + 1) begin
    //         // assign S[i] = 0;
    //         assign S[i + 1] = cell_s[i * (M-1)];
    //     end 
    // endgenerate

    // genvar k;
    // generate
    //     for(i = (N-1) * (M-1); i < N * (M-1); i = i + 1) begin
    //         // assign S[N + i - (N-1) * (M-1)] = 1;
    //         assign S[N + i - (N-1) * (M-1)] = cell_s[i];
    //     end
    // endgenerate

    // // assign S[N+M-1] = 0;
endmodule

module ArrayMultiplier_6x6_TB;
    parameter N = 6;
    parameter M = 6;

    reg [N-1:0] A;
    reg [N-1:0] B;

    wire [N+M-1:0] S;

    ArrayMultiplier_6x6 am(A, B, S);

    localparam P = 100;

    initial begin
        A = 1;
        B = 1;
        #P;

        A = 2;
        B = 3;
        #P

        A = 1;
        B = 4;
        #P;

        A = 3;
        B = 7;
        #P

        A = 10;
        B = 11;
        #P;
    end
endmodule