library verilog;
use verilog.vl_types.all;
entity ArrayMultiplier_6x6 is
    generic(
        N               : integer := 6;
        M               : integer := 6
    );
    port(
        A               : in     vl_logic_vector;
        B               : in     vl_logic_vector;
        S               : out    vl_logic_vector
    );
end ArrayMultiplier_6x6;
