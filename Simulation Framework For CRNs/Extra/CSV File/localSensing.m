Throughput25 = csvread ('PU_Interference_ratio_PPU(.25).csv'); 
Throughput15 = csvread ('PU_Interference_ratio_PPU(.15).csv'); 
Throughput00 = csvread ('PU_Interference_ratio_PPU(.0).csv'); 
ThroughputR25 = csvread ('PU_Interference_ratio(.25).csv'); 
ThroughputR15 = csvread ('PU_Interference_ratio(.15).csv'); 
ThroughputR00 = csvread ('PU_Interference_ratio(.0).csv'); 
x1= Throughput00 (:,1) ;% this is the results from probabilty of 0.0 
y1= Throughput15 (:,1) ;% this is the results from probabilty of 0.15
z1= Throughput25 (:,1) ;% this is the results from probabilty of 0.25
x2= ThroughputR00 (:,1) ;% this is the results from probabilty of 0.0 
y2= ThroughputR15 (:,1) ;% this is the results from probabilty of 0.15
z2= ThroughputR25 (:,1) ;% this is the results from probabilty of 0.25
figure(1)
hold on;
plot(x1,'b-o');
plot(y1,'g-*');
plot(z1,'r--^');
plot(x2,'p-.');
plot(y2,'m->');
plot(z2,'c--+');
xlabel('Bands','Fontweight','Bold');
ylabel('PU Interference','Fontweight','Bold');
title ('PU Interference VS BAND FOR ALL SUs','Fontweight','Bold');
legend ('Probabilty Of ACtivation 0.0(Local Sensing Allocation) ','Probabilty Of ACtivation 0.15 (Local Sensing Allocation)','Probabilty Of ACtivation 0.25 (Local Sensing Allocation)','Probabilty Of ACtivation 0.0 Random Allocation','Probabilty Of ACtivation 0.15 Random Allocation','Probabilty Of ACtivation 0.25 Random Allocation');
axis([0 100 0 1]); 
grid on;
hold off;