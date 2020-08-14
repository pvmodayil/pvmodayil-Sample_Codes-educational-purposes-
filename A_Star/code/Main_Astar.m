%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Program to find the shortest path via A* Graph Search Algo%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%-----------Importing the node and edge information----------
NodeHeuristicTable = readtable('nodes.csv');    
EdgeWeightTable = readtable('edges.csv');   
%NodeHeuristicTable              %printing the node table
%EdgeWeightTable                 %printing the edge table

heuristic = NodeHeuristicTable{:,4};     %storing the heuristic values into a vector
%heuristic                   %printing heuristic vector
%past cost list will contain initial past cost for all nodes which is
%infinity except for node 1(start node)
past_cost(1:size(heuristic))=Inf;
past_cost(1)=0;
%past_cost
totalcost=heuristic+past_cost'; %past_cost transpose is taken to add properly
%totalcost

%initialize the open and closed list
Open=[1];   %open list initially has a single value that is the starting node
Close=[];   %close list initially has no value
parent=0;   %parent is zero right now

weight=totalcost(Open(1));  %weight will have the value of the total cost of the node currently in position 1 of open list
weight
%starting the main while loop
%our aim is to continue untill the open list is empty
while(~isempty(Open))
    %now we shall go through the edge list to find the edges with the
    %starting node as of the node in Open list
    for i=1:height(EdgeWeightTable)
        if(Open(1)==EdgeWeightTable.ID2(i)&&~ismember(Open(1),Close))
                t=past_cost(Open(1))+EdgeWeightTable.cost(i)';  %temporary variable to hold new past cost so as to do comparison
                if(t<past_cost(EdgeWeightTable.ID1(i)))         %if the new past cost is less than that of node in open list
                    past_cost(EdgeWeightTable.ID1(i))=t;        %set that value as past cost
                    parent(EdgeWeightTable.ID1(i))=Open(1);     %set the node in open(1) as parent of current edge node
                    totalcost=heuristic+past_cost';             %set new totalcost
                    Open=[Open;EdgeWeightTable.ID1(i)];
                    weight=[weight;totalcost(EdgeWeightTable.ID1(i))']; %weight table corresponding to the nodes are updated with new minimum values 
                    weight                                      % printing
                end
        end
    end
    [weight,sortIdx]= sort(weight);                 %now the open list is sorted based on the total cost values so that the least cost node comes first in queue
        Open=Open(sortIdx);         %sorted Id is stored in the openlist so now Open(1) will be the least value node which was fully explored
        %Open
        close=[close;Open(1)];                      %store Open(1) fully explored node to Close
        Open=Open(2:end);                           %shift left Open so that next least value comes to Open(1)
        weight=weight(2:end);                       %do same for weight list
end%end while loop

%storing the parent values by traversing back from target node to create
%path
endpoint =  height(NodeHeuristicTable);
   
   h=height(NodeHeuristicTable);
   path(h)=height(NodeHeuristicTable)
   while(endpoint~=1)
      path(h-1)=parent(endpoint);
       endpoint=parent(endpoint);
       h=h-1;
   end
  path = nonzeros(path);
  path=path'
  csvwrite('path.csv',path)