% Author: Philip Varghese Modayil
% Revised on: 21-03-2021
function [voltage_left, voltage_right,flag] = NeuralController(sensor1,sensor2)
    
% Neural Network Initialization
W1 = 0.15;
W2 = 0.6;
W3 = 0.6;
W4 = 0.15;
T1 = 0;
T2 = 0;
flag=0;

MLS = sensor1*W1 + sensor2*W3 - T1;
MRS = sensor2*W4 + sensor1*W2 - T2;
if MLS > 0.5 && MRS > 0.5
     voltage_left = 8;
    voltage_right = 8;
elseif MLS <= 0.5 && MRS > 0.5
    voltage_left = -5;
    voltage_right = 5;
    flag = 1
elseif MLS > 0.5 && MRS <= 0.5
    voltage_left = 5;
    voltage_right = -5;
    flag = 1
elseif MLS <= 0.5 && MRS <=0.5
    voltage_left = -5;
    voltage_right = 5;
    flag = 1
end  
end