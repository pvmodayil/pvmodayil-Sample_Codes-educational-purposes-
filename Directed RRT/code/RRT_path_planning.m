clear;  %clear everything in work space
clc;    %clear command window
%program to find a path via implementing RRT algorithm
%initialization
xMin=-0.5; xMax=0.5;
yMin=-0.5; yMax=0.5;
xStart=xMin; yStart=yMin; %initial point for planner
xGoal=xMax; yGoal=yMax; %goal for planner
maxnodes=10;           %acceptable threshold for solution
flag=0; % to break if goal is reached
newweight=[0.9 0.1];
weightselect=1;
obstacles = readtable('obstacles.csv','HeaderLines',5);%reading the input obstacles table
%end of initialization

%setting the initial values
nodes(1).nod=1;
nodes(1).x=xStart;
nodes(1).y=yStart;
nodes(1).heuristic=sqrt(((xGoal-xStart)^2)+((yGoal-yStart)^2));
edges(1).N2=1;
edges(1).parent=0;
edges(1).cost=0;
xArray=xStart; yArray = yStart;
h=1;
flag=0;
%while loop start
 while (flag==0) 
    h % printing the iteration count
     %check whether the goal node is reached
    for j = 1:1:length(nodes)
        if nodes(j).x >= (xGoal-0.01)
            if nodes(j).y >= (yGoal-0.01)
                flag=1;
            end
        end
    end
    if length(nodes)==15
        flag=1; %max number of nodes is 15
    end
    if h==60
            flag=1; %if iteration goes beyond 60
    end
        % sample node with a random weight is calculated
            xSamp = nodes(length(nodes)).x+(xGoal-nodes(length(nodes)).x)*rand;
            ySamp = nodes(length(nodes)).y+(yGoal-nodes(length(nodes)).y)*rand;
        
        % finding the nearest node to the sample from the existing tree
        dist = Inf*ones(1,length(nodes));
           for j = 1:length(nodes)
            dist(j) = sqrt( (xSamp-nodes(j).x)^2 + (ySamp-nodes(j).y)^2 );
           end
        [val, ind] = min(dist);     %nearest node ind is obtained
        
        % a new node in the direction of sample
        newnodeX=nodes(ind).x+(xSamp-nodes(ind).x)*newweight(weightselect);
        newnodeY=nodes(ind).y+(ySamp-nodes(ind).y)*newweight(weightselect);
        % checking for obstacles
        cf=1; % setting the collision free flag to check again
        my=(newnodeY-nodes(ind).y); % slope from nearest to new
        mx=(newnodeX-nodes(ind).x);
        i=nodes(ind).x; j=nodes(ind).y;
        while (i<=newnodeX && j<=newnodeY)
            i=i+(0.001*mx); j=j+(0.001*my);
            for k=1:height(obstacles)
                d=sqrt(((i-obstacles.x0_0(k))^2)+((j-obstacles.x0_0_1(k))^2));
                if d <= ((obstacles.x0_2(k)/2))
                    cf=0;
                end
            end
        end
        if cf==1 %if no obstacle
            nodes(length(nodes)+1).x=newnodeX;
            nodes(length(nodes)).y=newnodeY;    %since previous step updates the node size 
            nodes(length(nodes)).nod=length(nodes);
            nodes(length(nodes)).heuristic=sqrt(((xGoal-newnodeX)^2)+((yGoal-newnodeY)^2));
            edges(length(edges)+1).parent=nodes(ind).nod;
            edges(length(edges)).N2=nodes(length(nodes)).nod;
            edges(length(edges)).cost=sqrt(((newnodeX-nodes(ind).x)^2)+((newnodeY-nodes(ind).y)^2));
            nodecount=length(nodes);
            nodes(length(nodes)).x
            nodes(length(nodes)).y
            if ((nodes(length(nodes)).x > 0) || (nodes(length(nodes)).y > 0))
                pushright=1;
            end
        end
        if cf==0 %if obstacle check again with different new node weight
            weightselect=2;
            newnodeX=nodes(ind).x+(xSamp-nodes(ind).x)*newweight(weightselect);
            newnodeY=nodes(ind).y+(ySamp-nodes(ind).y)*newweight(weightselect);
        % checking for obstacles
        cf=1; % setting the collision free flag to check again
        my=(newnodeY-nodes(ind).y); % slope
        mx=(newnodeX-nodes(ind).x);
        i=nodes(ind).x; j=nodes(ind).y;
        while (i<=newnodeX && j<=newnodeY)
            i=i+(0.001*mx); j=j+(0.001*my);
            for k=1:height(obstacles)
                d=sqrt(((i-obstacles.x0_0(k))^2)+((j-obstacles.x0_0_1(k))^2));
                if d <= ((obstacles.x0_2(k)/2))
                    cf=0;
                end
            end
        end
        if cf==1
            nodes(length(nodes)+1).x=newnodeX;
            nodes(length(nodes)).y=newnodeY;    %since previous step updates the node size 
            nodes(length(nodes)).nod=length(nodes);
            nodes(length(nodes)).heuristic=sqrt(((xGoal-newnodeX)^2)+((yGoal-newnodeY)^2));
            edges(length(edges)+1).parent=nodes(ind).nod;
            edges(length(edges)).N2=nodes(length(nodes)).nod;
            edges(length(edges)).cost=sqrt(((newnodeX-nodes(ind).x)^2)+((newnodeY-nodes(ind).y)^2));
            nodecount=length(nodes);
            nodes(length(nodes)).x
            nodes(length(nodes)).y
        end
        end
        weightselect=1; %re setting the weight
        h=h+1; %iteration count
end
nodetable=struct2table(nodes)
edgetable=struct2table(edges)
writetable(edgetable,'edges.csv');
writetable(nodetable,'nodes.csv');
for p=1:1:height(nodetable)
    path=[nodetable(p,1),path];
end
writetable(path,'path.csv');
