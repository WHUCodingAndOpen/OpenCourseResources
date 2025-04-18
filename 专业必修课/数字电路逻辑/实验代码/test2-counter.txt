module test (
    input [15:0]sw_i,
    output[6:0] disp_seg_o,
    output[7:0] disp_an_o,
    input wire rstn,
    input wire clk
);
    parameter div_para= 24;
    reg [31:0] count;
    reg [6:0] tmp;
    reg [3:0] cnt;
    wire clk_29;

    always @(posedge clk or negedge rstn) begin
        if(!rstn) count <= 0;
        else if (sw_i[0])
            count <= count + 1;
    end
    assign disp_an_o = 8'b11111110;
    assign clk_29 = count[div_para];
    always @(posedge clk_29 or negedge rstn) begin
        if(!rstn) cnt <= 4'b0000;
        else if(sw_i[0])
        begin
            
            case(cnt)
                4'b0000:tmp=7'b0111111;
                4'b0001:tmp=7'b0000110;
                4'b0010:tmp=7'b1011011;
                4'b0011:tmp=7'b1001111;
                4'b0100:tmp=7'b1100110;
                4'b0101:tmp=7'b1101101;
                4'b0110:tmp=7'b1111101;
                4'b0111:tmp=7'b0000111;
                4'b1000:tmp=7'b1111111;
                4'b1001: tmp=7'b1101111;  
                //以下为无效状态
                default:cnt <= 4'b0000;
               
            endcase
             cnt = cnt + 1;
        end
    end
    assign disp_seg_o = ~tmp;
endmodule