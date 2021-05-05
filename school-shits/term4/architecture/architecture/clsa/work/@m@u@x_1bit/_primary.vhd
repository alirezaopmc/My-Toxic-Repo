library verilog;
use verilog.vl_types.all;
entity MUX_1bit is
    generic(
        N               : integer := 1
    );
    port(
        a               : in     vl_logic_vector;
        b               : in     vl_logic_vector;
        s               : in     vl_logic;
        o               : out    vl_logic_vector
    );
end MUX_1bit;
