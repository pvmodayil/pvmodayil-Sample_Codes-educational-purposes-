%RUNMODEL - Main code to run robot model for ENG5009 class
%
%   NOTE: Students should only change the code between *---* markers
%
% Syntax: RunModel
%
% Inputs: none
% Outputs: none
% 
% Other m-files required: 
%   Sensor.m
%   WallGeneration.m
%   DynamicalModel.m
%   DrawRobot.m
%
% Author: Dr. Kevin Worrall
% Revised on: 06-01-2021
% Author: Philip Varghese Modayil
% Revised on: 21-03-2021

%% Preamble
close all;
clear all;
clc;

%% Simulation setup
% Time
simulationTime_total = 50;           % in seconds *------* YOU CAN CHANGE THIS
stepSize_time = 0.05;               % in seconds 

% Initial states and controls
voltage_left  = 6;                  % in volts *------* YOU CAN CHANGE THIS
voltage_right = 6;                  % in volts *------* YOU CAN CHANGE THIS

state_initial = zeros(1,24);        % VARIABLES OF IMPORTANCE:
                                    % state_initial(13): forward velocity,    v, m/s
                                    % state_initial(18): rotational velocity, r, rad/s
                                    % state_initial(19): current x-position,  x, m
                                    % state_initial(20): current y-position,  y, m
                                    % state_initial(24): heading angle,       psi, rad
                                    
% Environment
canvasSize_horizontal = 10;
canvasSize_vertical   = 10;
stepSize_canvas       = 0.01;

% *------------------------------------------*
%  YOU CAN ADD MORE SETUP HERE 
%  (e.g. setup of controller or checkpoints)
% *------------------------------------------*

%% Create Environment
obstacleMatrix = zeros(canvasSize_horizontal / stepSize_canvas, canvasSize_vertical / stepSize_canvas);

% Generate walls
% --> the variable "obstacleMatrix" is updated for each added wall
[wall_1, obstacleMatrix] = WallGeneration( -1,  1, 1.2, 1.2, 'h', obstacleMatrix); 
[wall_2, obstacleMatrix] = WallGeneration( -3, -3,  -2,   2, 'v', obstacleMatrix);
[wall_3, obstacleMatrix] = WallGeneration( -3,  1,   4,   4, 'h', obstacleMatrix);
[wall_4, obstacleMatrix] = WallGeneration(  2,  2,  -3,   1, 'v', obstacleMatrix);
% *---------------------------*
%  YOU CAN ADD MORE WALLS HERE
% *---------------------------*
Wall_p = [0 3; 1 2; -1 4; -1 -2; -0.2 2;];
marker = 1;
tolerance = 0.05;




%% Main simulation
% Initialize simulation 
timeSteps_total = simulationTime_total/stepSize_time;
state = state_initial;
time = 0;

%timer = 0
%maxtime = 10


% Run simulation
for timeStep = 1:timeSteps_total
    
    
    % *-------------------------------------*
    %  YOU CAN ADD/CHANGE YOUR CONTROLS HERE
    % *-------------------------------------*
 
    sensorOut = Sensor(state(timeStep,19), state(timeStep,20), state(timeStep,24), obstacleMatrix);
    leftSensor = sensorOut(1);
    rightSensor = sensorOut(2);
    
    checkpoint = [Wall_p(marker, 1), Wall_p(marker, 2)];
    
    [booleanAtCheckpoint, newHeadingAngle] = ComputeHeadingAngle( state(timeStep,19:20), checkpoint, tolerance);
    
     dheadingAngle = newHeadingAngle - state(timeStep,24)
     if dheadingAngle < -pi
        dheadingAngle = dheadingAngle + 2*pi
    elseif dheadingAngle > pi
        dheadingAngle = dheadingAngle - 2*pi
     end
    
    
     % Motion of robot
     if dheadingAngle > 0.3
         % Move robot right
         voltage_left  = 6;                  % in volts *------* YOU CAN CHANGE THIS
         voltage_right = -6;                  % in volts *------* YOU CAN CHANGE THIS
     elseif dheadingAngle < 0
         % Move robot left
          voltage_left  = -6;                  % in volts *------* YOU CAN CHANGE THIS
          voltage_right = 6;                  % in volts *------* YOU CAN CHANGE THIS
     else
         % Move robot straight
         voltage_left = 6;
         voltage_right = 6;
     end
    if booleanAtCheckpoint == 1
        marker = marker + 1;
    end
    
    if marker == 6
        break;
    end
     
    %Fuzzy = readfis ('FuzzyObstaclenear');
    %outputVoltages = evalfis(Fuzzy, sensorOut);
    %voltage_left = outputVoltages (1);
    %voltage_right = outputVoltages (2);
    
    % Assign voltage applied to wheels
    voltages = [voltage_left; voltage_left; voltage_right; voltage_right];
    % Run model *** DO NOT CHANGE
    [state_derivative(timeStep,:), state(timeStep,:)] = DynamicalModel(voltages, state(timeStep,:), stepSize_time);   
    
    % Euler intergration *** DO NOT CHANGE
    state(timeStep + 1,:) = state(timeStep,:) + (state_derivative(timeStep,:) * stepSize_time); 
    time(timeStep + 1)    = timeStep * stepSize_time;
    
    % Plot robot on canvas  *------* YOU CAN ADD STUFF HERE
    figure(1); clf; hold on; grid on; axis([-5,5,-5,5]);
    DrawRobot(0.2, state(timeStep,20), state(timeStep,19), state(timeStep,24), 'b');
    
    plot(checkpoint(:,2),checkpoint(:,1),'g*')
    
   % plot(wall_1(:,1), wall_1(:,2),'k-');
    %plot(wall_2(:,1), wall_2(:,2),'k-'); 
    xlabel('y, m'); ylabel('x, m');
end

%% Plot results
% *----------------------------------*
%  YOU CAN ADD OR CHANGE FIGURES HERE
%  don't forget to add axis labels!
% *----------------------------------*

figure(2); hold on; grid on;
plot(state(:,20), state(:,19));
xlabel('y, m'); ylabel('x, m');
figure(3); hold on; grid on;
plot(time, state(:,19));
xlabel('time, s'); ylabel('x, m');
figure(4); hold on; grid on;
plot(time, state(:,24));
xlabel ('time, s'); ylabel('Heading angle (psi, rad)');
