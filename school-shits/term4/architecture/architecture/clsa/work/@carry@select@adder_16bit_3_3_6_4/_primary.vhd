library verilog;
use verilog.vl_types.all;
entity CarrySelectAdder_16bit_3_3_6_4 is
    generic(
        N               : integer := 16;
        G               : integer := 4
    );
    port(
        a               : in     vl_logic_vector;
        b               : in     vl_logic_vector;
        cin             : in     vl_logic;
        s               : out    vl_logic_vector;
        cout            : out    vl_logic
    );
end CarrySelectAdder_16bit_3_3_6_4;
