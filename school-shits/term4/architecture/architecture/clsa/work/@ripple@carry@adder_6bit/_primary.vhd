library verilog;
use verilog.vl_types.all;
entity RippleCarryAdder_6bit is
    generic(
        N               : integer := 6
    );
    port(
        a               : in     vl_logic_vector;
        b               : in     vl_logic_vector;
        cin             : in     vl_logic;
        s               : out    vl_logic_vector;
        cout            : out    vl_logic
    );
end RippleCarryAdder_6bit;
