% Ploting Throughput Results 
%%%%%%%% names of the files that will be imported 
Throughput25 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU.25.csv'); 
Throughput15 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU.15.csv'); 
Throughput00 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU0.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= Throughput00 (:,1) % this is the results from probabilty of 0.0 
y= Throughput15 (:,1) % this is the results from probabilty of 0.15
z= Throughput25 (:,1) % this is the results from probabilty of 0.25

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
xlabel('Bands','Fontweight','Bold');
ylabel('Throughput','Fontweight','Bold');
title ('Throughput VS BAND FOR ALL SUs','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Ploting Utilization Results 
%%%%%%%% names of the files that will be imported 
Utilization25 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_PPU.25.csv'); 
Utilization15 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_PPU.15.csv'); 
Utilization00 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_PPU0.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= Utilization00 (:,1) % this is the results from probabilty of 0.0 
y= Utilization15 (:,1) % this is the results from probabilty of 0.15
z= Utilization25 (:,1) % this is the results from probabilty of 0.25

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
xlabel('Bands','Fontweight','Bold');
ylabel('Utilization','Fontweight','Bold');
title ('Utilization VS BAND FOR ALL SUs','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Ploting SU sucessful transmission  Results 
%%%%%%%% names of the files that will be imported 
SucessfulTransmission25 = csvread ('SucessfulTransmission_VS_BAND_FOR_ALLSUs_PPU.25.csv'); 
SucessfulTransmission15 = csvread ('SucessfulTransmission_VS_BAND_FOR_ALLSUs_PPU.15.csv'); 
SucessfulTransmission00 = csvread ('SucessfulTransmission_VS_BAND_FOR_ALLSUs_PPU0.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= SucessfulTransmission00 (:,1) % this is the results from probabilty of 0.0 
y= USucessfulTransmission15 (:,1) % this is the results from probabilty of 0.15
z= SucessfulTransmission25 (:,1) % this is the results from probabilty of 0.25

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
xlabel('Bands','Fontweight','Bold');
ylabel('SucessfulTransmission','Fontweight','Bold');
title ('SucessfulTransmission VS BAND FOR ALL SUs','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Ploting SU Collisions Results 
%%%%%%%% names of the files that will be imported 
Collision25 = csvread ('Collision_VS_TimeSlot_FOR_ALLSUs_PPU.25.csv'); 
Collision15 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU.15.csv'); 
Collision00 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU0.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= Collision00 (:,1) % this is the results from probabilty of 0.0 
y= Collision15 (:,1) % this is the results from probabilty of 0.15
z= Collision25 (:,1) % this is the results from probabilty of 0.25

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
xlabel('Bands','Fontweight','Bold');
ylabel('Collision','Fontweight','Bold');
title ('Collision VS Time Slot FOR ALL SUs','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Ploting PU Interferance Ratio Results 
%%%%%%%% names of the files that will be imported 
PUinterferance25 = csvread ('PU_Interfrance_ratio.25.csv'); 
PUinterferance15 = csvread ('PU_Interfrance_ratio.15.csv'); 
PUinterferance00 = csvread ('PU_Interfrance_ratio0.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= PUinterferance00 (:,1) % this is the results from probabilty of 0.0 
y= PUinterferance15 (:,1) % this is the results from probabilty of 0.15
z= PUinterferancet25 (:,1) % this is the results from probabilty of 0.25

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
xlabel('Bands','Fontweight','Bold');
ylabel('PUinterferance','Fontweight','Bold');
title ('PUinterferance VS BAND FOR ALL PUs','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Ploting Sucessful SU4  VS Time  Results 
%%%%%%%% names of the files that will be imported 
SU4BANDS25 = csvread ('SU4BANDS.25.csv'); 
SU4BANDS15 = csvread ('SU4BANDS.15.csv'); 
SU4BANDS00 = csvread ('SU4BANDS0.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= SU4BANDS00 (:,1) % this is the results from probabilty of 0.0 
y= SU4BANDSt15 (:,1) % this is the results from probabilty of 0.15
z= SU4BANDS25 (:,1) % this is the results from probabilty of 0.25

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
xlabel('Time SLOTS','Fontweight','Bold');
ylabel('SU4BANDS','Fontweight','Bold');
title ('SU4BANDS VS Time slots for SU4','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Ploting False alaram for all SUs  VS Time  Results 
%%%%%%%% names of the files that will be imported 
SUFA25 = csvread ('SUFA.25.csv'); 
SUFA15 = csvread ('SUFA.15.csv'); 
SUFA00 = csvread ('SUFA0.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= SUFA00 (:,1) % this is the results from probabilty of 0.0 
y= SUFA15 (:,1) % this is the results from probabilty of 0.15
z= SUFA25 (:,1) % this is the results from probabilty of 0.25

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
xlabel('Time SLOT','Fontweight','Bold');
ylabel('SU False Alarms Avereged Over Time Slots','Fontweight','Bold');
title ('SU False Alarms Avereged Over Time Slots For Each SU','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Ploting Miss-Detecction for all SUs  VS Time  Results 
%%%%%%%% names of the files that will be imported 
SUMD25 = csvread ('SUMD.25.csv'); 
SUMD15 = csvread ('SUMD.15.csv'); 
SUMD00 = csvread ('SUMD0.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= SUMD00 (:,1) % this is the results from probabilty of 0.0 
y= SUMD15 (:,1) % this is the results from probabilty of 0.15
z= SUMD25 (:,1) % this is the results from probabilty of 0.25

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
xlabel('Time slot','Fontweight','Bold');
ylabel('SU Miss detection Avereged Over Time Slots','Fontweight','Bold');
title ('SU Miss Detection Avereged Over Time Slots For Each SU','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Ploting Changing The Load VS Bands Taken For SUs for all SUs  VS Time  Results 
%%%%%%%% names of the files that will be imported 

NOOFSU5 = csvread ('NUMBER_0F_SU5.csv'); 
NOOFSU8 = csvread ('NUMBER_0F_SU8.csv'); 
NOOFSU10 = csvread ('NUMBER_0F_SU10.csv'); 
NOOFSU12 = csvread ('NUMBER_0F_SU12.csv'); 
NOOFSU15 = csvread ('NUMBER_0F_SU15.csv'); 


%%%%%%% importing the first colume of each trail to get the graph going on 

x= NOOFSU5 (:,1) % this is the results from having 5 SU 
y= NOOFSU8 (:,1) % this is the results from having 8 SU 
z= NOOFSU10 (:,1) % this is the results from having 10 SU
H= NOOFSU12 (:,1) % this is the results from having 12 SU 
G= NOOFSU15 (:,1) % this is the results from having 15 SU 

%%%%%%%%%% the Drawing process 
hold on;
plot(x,'Color','blue','LineWidth',2.0);
plot(y,'Color','red','linewidth',2.0,'LineStyle','-.');
plot(z,'Color','green','LineWidth',2.0,'LineStyle','-.');
plot(H,'Color','black','LineWidth',2.0,'LineStyle','-.');
plot(G,'Color','yellow','LineWidth',2.0,'LineStyle','-.');

xlabel('SU ID','Fontweight','Bold');
ylabel('Average Value of Used Bands for each SU  ','Fontweight','Bold');
title ('Changing The Load VS Bands Taken For SUs for all SUs','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ');
grid on;







