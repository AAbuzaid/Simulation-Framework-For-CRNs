classdef Appeee13 < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                  matlab.ui.Figure
        TabGroup                  matlab.ui.container.TabGroup
        MainTab                   matlab.ui.container.Tab
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel  matlab.ui.control.Label
        AfteryouputthefilesswitchONtheSimulatorSwitch  matlab.ui.control.ToggleSwitch
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_11  matlab.ui.control.Label
        CRNSimulatorBetaV02Label  matlab.ui.control.Label
        ThroughputTab             matlab.ui.container.Tab
        UIAxes_1                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_2  matlab.ui.control.Label
        UtilizationTab            matlab.ui.container.Tab
        UIAxes_2                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_3  matlab.ui.control.Label
        SuSUCESSFULtxTab          matlab.ui.container.Tab
        UIAxes_3                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_4  matlab.ui.control.Label
        SUcollisionsTab           matlab.ui.container.Tab
        UIAxes_4                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_5  matlab.ui.control.Label
        PUinterferanceRatioTab    matlab.ui.container.Tab
        UIAxes_5                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_6  matlab.ui.control.Label
        SucessfulS4Tab            matlab.ui.container.Tab
        UIAxes_6                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_7  matlab.ui.control.Label
        CooperatvesensingFATab    matlab.ui.container.Tab
        UIAxes_7                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_8  matlab.ui.control.Label
        CooperativeSensingMDTab   matlab.ui.container.Tab
        UIAxes_8                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_9  matlab.ui.control.Label
        ChangingLoadTab           matlab.ui.container.Tab
        UIAxes_9                  matlab.ui.control.UIAxes
        AfteryouputthefilesswitchONtheSimulatorSwitchLabel_10  matlab.ui.control.Label
    end

    methods (Access = private)

        % Value changed function: 
        % AfteryouputthefilesswitchONtheSimulatorSwitch
        function AfteryouputthefilesswitchONtheSimulatorSwitchValueChanged(app, event)
            value = app.AfteryouputthefilesswitchONtheSimulatorSwitch.Value;
             % Ploting Throughput Results 
            %%%%%%%% names of the files that will be imported 
           
            Throughput25 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU(.25).csv'); 
            Throughput15 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU(.15).csv'); 
            Throughput00 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU(.0).csv');
            Throughputcoop25 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_Coop_PPU(.25).csv'); 
            Throughputcoop15 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_Coop_PPU(.15).csv'); 
            Throughputcoop00 = csvread ('THROUGHPUT_VS_BAND_FOR_ALLSUs_Coop_PPU(.0).csv');
            
            
            
             
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x1= Throughput00 (:,1) ;% this is the results from probabilty of 0.0 
            y1= Throughput15 (:,1) ;% this is the results from probabilty of 0.15
            z1= Throughput25 (:,1) ;% this is the results from probabilty of 0.25
             x1coop= Throughputcoop00 (:,1); % this is the results from probabilty of 0.0  COOPRATIVE
            y1coop= Throughputcoop15 (:,1); % this is the results from probabilty of 0.15 COOPRATIVE 
            z1coop= Throughputcoop25 (:,1); % this is the results from probabilty of 0.25 COOPRATIVE 
            
            
            
            %%%%%%%%%% the Drawing process 
             
            hold (app.UIAxes_1) ;
          
            plot(app.UIAxes_1,x1,'Color','blue','LineWidth',2.0,'Marker','*');
            plot(app.UIAxes_1,y1,'Color','red','linewidth',2.0,'LineStyle','-.','Marker','o');
            plot(app.UIAxes_1,z1,'Color','green','LineWidth',2.0,'LineStyle','-.','Marker','s');
            plot(app.UIAxes_1,x1coop,'Color','black','LineWidth',2.0,'LineStyle','-.','Marker','x');
            plot(app.UIAxes_1,y1coop,'Color','black','LineWidth',2.0,'LineStyle','--','Marker','+');
            plot(app.UIAxes_1,z1coop,'Color','black','LineWidth',2.0,'LineStyle',':','Marker','hexagram');
            
            xlabel(app.UIAxes_1,'Bands','Fontweight','Bold');
            ylabel(app.UIAxes_1,'Throughput','Fontweight','Bold');
            ylim(app.UIAxes_1,[0 1]);
            title (app.UIAxes_1,'Throughput VS BAND FOR ALL SUs','Fontweight','Bold');
            legend (app.UIAxes_1,'Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ','Probabilty Of ACtivation 0.0 cooperative  ','Probabilty Of ACtivation 0.15 cooperative','Probabilty Of ACtivation 0.25 cooperative');
            grid on;
            
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%
              % Ploting Utilization Results 
            %%%%%%%% names of the files that will be imported 
            Utilization25 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_PPU(.25).csv'); 
            Utilization15 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_PPU(.15).csv'); 
            Utilization00 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_PPU(.0).csv'); 
            
             Utilizationcoop25 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_Coop_PPU(.25).csv'); 
            Utilizationcoop15 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_Coop_PPU(.15).csv'); 
            Utilizationcoop00 = csvread ('Utilization_VS_BAND_FOR_ALLSUs_Coop_PPU(.0).csv'); 
            
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x2= Utilization00 (:,1); % this is the results from probabilty of 0.0 
            y2= Utilization15 (:,1) ;% this is the results from probabilty of 0.15
            z2= Utilization25 (:,1) ;% this is the results from probabilty of 0.25
            x2COOP= Utilizationcoop00 (:,1); % this is the results from probabilty of 0.0 
            y2COOP= Utilizationcoop15 (:,1) ;% this is the results from probabilty of 0.15
            z2COOP= Utilizationcoop25 (:,1); % this is the results from probabilty of 0.25
            
            %%%%%%%%%% the Drawing process 
            hold (app.UIAxes_2);
            
            
            plot(x2,'Color','blue','LineWidth',2.0, 'Marker','*');
            plot(app.UIAxes_2,y2,'Color','red','linewidth',2.0,'LineStyle','-.','Marker','O');
            plot(app.UIAxes_2,z2,'Color','green','LineWidth',2.0,'LineStyle','-.','Marker','S');
            plot(app.UIAxes_2,x2COOP,'Color','black','LineWidth',2.0,'Marker','x');
            plot(app.UIAxes_2,y2COOP,'Color','black','linewidth',2.0,'LineStyle','-.','Marker','+');
            plot(app.UIAxes_2,z2COOP,'Color','black','LineWidth',2.0,'LineStyle','-.','Marker','hexagram');
            
           
                   ylim(app.UIAxes_2,[0 1]);

            xlabel(app.UIAxes_2,'Bands','Fontweight','Bold');
            ylabel(app.UIAxes_2,'Utilization','Fontweight','Bold');
            title (app.UIAxes_2,'Utilization VS BAND FOR ALL SUs','Fontweight','Bold');
            legend (app.UIAxes_2, 'Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ','Probabilty Of ACtivation 0.0 cooperative  ','Probabilty Of ACtivation 0.15 cooperative','Probabilty Of ACtivation 0.25 cooperative');
            grid on;
                        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
             % Ploting SU sucessful transmission  Results 
            %%%%%%%% names of the files that will be imported 
            SucessfulTransmission25 = csvread ('SuccessfulTransmission_VS_BAND_FOR_ALLSUs_PPU(.25).csv'); 
            SucessfulTransmission15 = csvread ('SuccessfulTransmission_VS_BAND_FOR_ALLSUs_PPU(.15).csv'); 
            SucessfulTransmission00 = csvread ('SuccessfulTransmission_VS_BAND_FOR_ALLSUs_PPU(.0).csv'); 
            
            SucessfulTransmissioncoop25 = csvread ('SuccessfulTransmission_VS_BAND_FOR_ALLSUs_Coop_PPU(.25).csv'); 
            SucessfulTransmissioncoop15 = csvread ('SuccessfulTransmission_VS_BAND_FOR_ALLSUs_Coop_PPU(.15).csv'); 
            SucessfulTransmissioncoop00 = csvread ('SuccessfulTransmission_VS_BAND_FOR_ALLSUs_Coop_PPU(.0).csv'); 
            
            
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x3= SucessfulTransmission00 (:,1) ; % this is the results from probabilty of 0.0 
            y3= SucessfulTransmission15 (:,1) ;% this is the results from probabilty of 0.15
            z3= SucessfulTransmission25 (:,1); % this is the results from probabilty of 0.25
            x3COOP= SucessfulTransmissioncoop00 (:,1); % this is the results from probabilty of 0.0 
            y3COOP= SucessfulTransmissioncoop15 (:,1); % this is the results from probabilty of 0.15
            z3COOP= SucessfulTransmissioncoop25 (:,1); % this is the results from probabilty of 0.25
            
            %%%%%%%%%% the Drawing process 
            hold (app.UIAxes_3) ;
            plot(app.UIAxes_3,x3,'Color','blue','LineWidth',2.0, 'Marker','*');
            plot(app.UIAxes_3,y3,'Color','red','linewidth',2.0,'LineStyle','-.', 'Marker','O');
            plot(app.UIAxes_3,z3,'Color','green','LineWidth',2.0,'LineStyle','-.', 'Marker','S');
            plot(app.UIAxes_3,x3COOP,'Color','black','LineWidth',2.0, 'Marker','x');
            plot(app.UIAxes_3,y3COOP,'Color','black','linewidth',2.0,'LineStyle','-.', 'Marker','+');
            plot(app.UIAxes_3,z3COOP,'Color','black','LineWidth',2.0,'LineStyle','-.', 'Marker','hexagram');
            xlabel(app.UIAxes_3,'Bands','Fontweight','Bold');
            ylabel(app.UIAxes_3,'SucessfulTransmission','Fontweight','Bold');
            title (app.UIAxes_3,'SucessfulTransmission VS BAND FOR ALL SUs','Fontweight','Bold');
            legend (app.UIAxes_3,'Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ','Probabilty Of ACtivation 0.0 cooperative  ','Probabilty Of ACtivation 0.15 cooperative','Probabilty Of ACtivation 0.25 cooperative');
            grid on;
             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
              % Ploting SU Collisions Results 
            %%%%%%%% names of the files that will be imported 
            Collision25 = csvread ('Collision_VS_SUID_FOR_ALLBANDs_PPU(.25).csv'); 
            Collision15 = csvread ('Collision_VS_SUID_FOR_ALLBANDs_PPU(.15).csv'); 
            Collision00 = csvread ('Collision_VS_SUID_FOR_ALLBANDs_PPU(.0).csv'); 
            Collisioncoop25 = csvread ('Collision_VS_SUID_FOR_ALLBANDs_Coop_PPU(.25).csv'); 
            Collisioncoop15 = csvread ('Collision_VS_SUID_FOR_ALLBANDs_Coop_PPU(.15).csv'); 
            Collisioncoop00 = csvread ('Collision_VS_SUID_FOR_ALLBANDs_Coop_PPU(.0).csv'); 
            
            
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x4= Collision00 (:,1) ;% this is the results from probabilty of 0.0 
            y4= Collision15 (:,1) ;% this is the results from probabilty of 0.15
            z4= Collision25 (:,1) ;% this is the results from probabilty of 0.25
            x4coop= Collisioncoop00 (:,1); % this is the results from probabilty of 0.0 
            y4coop= Collisioncoop15 (:,1); % this is the results from probabilty of 0.15
            z4coop= Collisioncoop25 (:,1) ;% this is the results from probabilty of 0.25
            
            
            %%%%%%%%%% the Drawing process 
            hold (app.UIAxes_4);
            plot(app.UIAxes_4,x4,'Color','blue','LineWidth',2.0,'Marker','*');
            plot(app.UIAxes_4,y4,'Color','red','linewidth',2.0,'LineStyle','-.','Marker','o');
            plot(app.UIAxes_4,z4,'Color','green','LineWidth',2.0,'LineStyle','-.','Marker','s');
            plot(app.UIAxes_4,x4coop,'Color','black','LineWidth',2.0,'Marker','X');
            plot(app.UIAxes_4,y4coop,'Color','black','linewidth',2.0,'LineStyle','-.','Marker','+');
            plot(app.UIAxes_4,z4coop,'Color','black','LineWidth',2.0,'LineStyle','-.','Marker','hexagram');
            xlabel(app.UIAxes_4,'Bands','Fontweight','Bold');
            ylabel(app.UIAxes_4,'Collision','Fontweight','Bold');
            title (app.UIAxes_4,'Collision VS Time Slot FOR ALL SUs','Fontweight','Bold');
            legend (app.UIAxes_4,'Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ','Probabilty Of ACtivation 0.0 cooperative  ','Probabilty Of ACtivation 0.15 cooperative','Probabilty Of ACtivation 0.25 cooperative');
            grid on;
            
                        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
               % Ploting PU Interferance Ratio Results 
            %%%%%%%% names of the files that will be imported 
            PUinterferance25 = csvread ('PU_Interference_ratio_PPU(.25).csv'); 
            PUinterferance15 = csvread ('PU_Interference_ratio_PPU(.15).csv'); 
            PUinterferance00 = csvread ('PU_Interference_ratio_PPU(.0).csv'); 
            PUinterferancecoop25 = csvread ('PU_Interference_ratio_Coop_PPU(.25).csv'); 
            PUinterferancecoop15 = csvread ('PU_Interference_ratio_Coop_PPU(.15).csv'); 
            PUinterferancecoop00 = csvread ('PU_Interference_ratio_Coop_PPU(.0).csv'); 
            
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x5= PUinterferance00 (:,1) ;% this is the results from probabilty of 0.0 
            y5= PUinterferance15 (:,1) ;% this is the results from probabilty of 0.15
            z5= PUinterferance25 (:,1); % this is the results from probabilty of 0.25
            x5coop= PUinterferancecoop00 (:,1) ;% this is the results from probabilty of 0.0 
            y5coop= PUinterferancecoop15 (:,1) ;% this is the results from probabilty of 0.15
            z5coop= PUinterferancecoop25 (:,1) ;% this is the results from probabilty of 0.25
            
            %%%%%%%%%% the Drawing process 
            hold (app.UIAxes_5);
            plot(app.UIAxes_5,x5,'Color','blue','LineWidth',2.0,'Marker','*');
            plot(app.UIAxes_5,y5,'Color','red','linewidth',2.0,'LineStyle','-.','Marker','o');
            plot(app.UIAxes_5,z5,'Color','green','LineWidth',2.0,'LineStyle','-.','Marker','s');
            plot(app.UIAxes_5,x5coop,'Color','black','LineWidth',2.0,'Marker','x');
            plot(app.UIAxes_5,y5coop,'Color','black','linewidth',2.0,'LineStyle','-.','Marker','+');
            plot(app.UIAxes_5,z5coop,'Color','black','LineWidth',2.0,'LineStyle','-.','Marker','hexagram');
            xlabel(app.UIAxes_5,'Bands','Fontweight','Bold');
                        ylim(app.UIAxes_5,[0 1]);

            ylabel(app.UIAxes_5,'PUinterferance','Fontweight','Bold');
            title (app.UIAxes_5,'PUinterferance VS BAND FOR ALL PUs','Fontweight','Bold');
            legend (app.UIAxes_5,'Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ','Probabilty Of ACtivation 0.0 cooperative  ','Probabilty Of ACtivation 0.15 cooperative','Probabilty Of ACtivation 0.25 cooperative');
            grid on;
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
              % Ploting Sucessful SU4  VS Time  Results 
            %%%%%%%% names of the files that will be imported 
           %% SU4BANDS25 = csvread ('Successful_VS_Time_FOR_SU(4)_Deterministic.csv'); 
            %%SU4BANDS15 = csvread ('Successful_VS_Time_FOR_SU4_PPU.15.csv'); 
            SU4BANDS00 = csvread ('Successful_VS_Time_FOR_SU(4)_Deterministic.csv'); 
            
            
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x6= SU4BANDS00 (:,1); % this is the results from probabilty of 0.0 
            %%y6= SU4BANDSt15 (:,1) % this is the results from probabilty of 0.15
            %%z6= SU4BANDS25 (:,1) % this is the results from probabilty of 0.25
            
            %%%%%%%%%% the Drawing process 
            hold (app.UIAxes_6)
            %plot(app.UIAxes_6,x6,'Color','blue','LineWidth',2.0,'LineStyle','-');
            plot(app.UIAxes_6,x6,'r-');
            %plot(app.UIAxes_6,y6,'Color','red','linewidth',2.0,'LineStyle','-.');
            %plot(app.UIAxes_6,z6,'Color','green','LineWidth',2.0,'LineStyle','-.');
            xlabel(app.UIAxes_6,'Time SLOTS','Fontweight','Bold');
            ylabel(app.UIAxes_6,'SU4BANDS','Fontweight','Bold');
            title (app.UIAxes_6,'SU4BANDS VS Time slots for SU4','Fontweight','Bold');
            legend (app.UIAxes_6,'Successful_VS_Time_FOR_SU(4) ');
            grid on;
                        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            
            
           % Ploting False alaram for all SUs  VS Time  Results 
            %%%%%%%% names of the files that will be imported 
            SUFA25 = csvread ('PFA_VS_SUID_FOR_ALLBANDs_PPU(.25).csv'); 
            SUFA15 = csvread ('PFA_VS_SUID_FOR_ALLBANDs_PPU(.15).csv'); 
            SUFA00 = csvread ('PFA_VS_SUID_FOR_ALLBANDs_PPU(.0).csv'); 
             SUFAcoop25 = csvread ('PFA_VS_SUID_FOR_ALLBANDs_PPU(.25).csv'); 
            SUFAcoop15 = csvread ('PFA_VS_SUID_FOR_ALLBANDs_PPU(.15).csv'); 
            SUFAcoop00 = csvread ('PFA_VS_SUID_FOR_ALLBANDs_PPU(.0).csv'); 
            
            
            
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x7= SUFA00 (:,1) ;% this is the results from probabilty of 0.0 
            y7= SUFA15 (:,1) ;% this is the results from probabilty of 0.15
            z7= SUFA25 (:,1) ;% this is the results from probabilty of 0.25
            x7coop= SUFAcoop00 (:,1); % this is the results from probabilty of 0.0 
            y7coop= SUFAcoop15 (:,1) ;% this is the results from probabilty of 0.15
            z7coop= SUFAcoop25(:,1) ;% this is the results from probabilty of 0.25
            
            %%%%%%%%%% the Drawing process 
            hold (app.UIAxes_7)
            plot(app.UIAxes_7,x7,'Color','blue','LineWidth',2.0,'Marker','*');
            plot(app.UIAxes_7,y7,'Color','red','linewidth',2.0,'LineStyle','-.','Marker','o');
            plot(app.UIAxes_7,z7,'Color','green','LineWidth',2.0,'LineStyle','-.','Marker','s');
            plot(app.UIAxes_7,x7coop,'Color','black','LineWidth',2.0,'Marker','X');
            plot(app.UIAxes_7,y7coop,'Color','black','linewidth',2.0,'LineStyle','-.','Marker','+');
            plot(app.UIAxes_7,z7coop,'Color','black','LineWidth',2.0,'LineStyle','-.','Marker','hexagram');
            xlabel(app.UIAxes_7,'Time SLOT','Fontweight','Bold');
            ylabel(app.UIAxes_7,'SU False Alarms Avereged Over Time Slots','Fontweight','Bold');
            title (app.UIAxes_7,'SU False Alarms Avereged Over Time Slots For Each SU','Fontweight','Bold');
            legend (app.UIAxes_7,'Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ','Probabilty Of ACtivation 0.0 cooperative  ','Probabilty Of ACtivation 0.15 cooperative','Probabilty Of ACtivation 0.25 cooperative');
            grid on;
               %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%
              % Ploting Miss-Detecction for all SUs  VS Time  Results 
            %%%%%%%% names of the files that will be imported 
            SUMD25 = csvread ('PMD_VS_SUID_FOR_ALLBANDs_Coop_PPU(.25).csv'); 
            SUMD15 = csvread ('PMD_VS_SUID_FOR_ALLBANDs_Coop_PPU(.15).csv'); 
            SUMD00 = csvread ('PMD_VS_SUID_FOR_ALLBANDs_Coop_PPU(.0).csv'); 
            SUMDcoop25 = csvread ('PMD_VS_SUID_FOR_ALLBANDs_Coop_PPU(.25).csv'); 
            SUMDcoop15 = csvread ('PMD_VS_SUID_FOR_ALLBANDs_Coop_PPU(.15).csv'); 
            SUMDcoop00 = csvread ('PMD_VS_SUID_FOR_ALLBANDs_Coop_PPU(.0).csv'); 
            
            
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x8= SUMD00 (:,1); % this is the results from probabilty of 0.0 
            y8= SUMD15 (:,1) ;% this is the results from probabilty of 0.15
            z8= SUMD25 (:,1); % this is the results from probabilty of 0.25
            x8coop= SUMDcoop00 (:,1) ;% this is the results from probabilty of 0.0 
            y8coop= SUMDcoop15 (:,1) ;% this is the results from probabilty of 0.15
            z8coop= SUMDcoop25 (:,1); % this is the results from probabilty of 0.25
            
            %%%%%%%%%% the Drawing process 
            hold (app.UIAxes_8)
            plot(app.UIAxes_8,x8,'Color','blue','LineWidth',2.0,'Marker','*');
            plot(app.UIAxes_8,y8,'Color','red','linewidth',2.0,'LineStyle','-.','Marker','o');
            plot(app.UIAxes_8,z8,'Color','green','LineWidth',2.0,'LineStyle','-.','Marker','s');
            plot(app.UIAxes_8,x8coop,'Color','black','LineWidth',2.0,'Marker','X');
            plot(app.UIAxes_8,y8coop,'Color','black','linewidth',2.0,'LineStyle','-.','Marker','+');
            plot(app.UIAxes_8,z8coop,'Color','black','LineWidth',2.0,'LineStyle','-.','Marker','hexagram');
            xlabel(app.UIAxes_8,'Time slot','Fontweight','Bold');
            ylabel(app.UIAxes_8,'SU Miss detection Avereged Over Time Slots','Fontweight','Bold');
            title (app.UIAxes_8,'SU Miss Detection Avereged Over Time Slots For Each SU','Fontweight','Bold');
            legend (app.UIAxes_8,'Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ','Probabilty Of ACtivation 0.0 cooperative  ','Probabilty Of ACtivation 0.15 cooperative','Probabilty Of ACtivation 0.25 cooperative');
            grid on;
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%
            
             % Ploting Changing The Load VS Bands Taken For SUs for all SUs  VS Time  Results 
            %%%%%%%% names of the files that will be imported 
            
            succs00 = csvread ('SuccessfulTransmission_VS_CHNANGING_LOADS_FOR_ALLSUs_PPU(.0).csv'); 
            succs15 = csvread ('SuccessfulTransmission_VS_CHNANGING_LOADS_FOR_ALLSUs_PPU(.15).csv'); 
            succs25 = csvread ('SuccessfulTransmission_VS_CHNANGING_LOADS_FOR_ALLSUs_PPU(.25).csv'); 
            succscoop00 = csvread ('SuccessfulTransmission_VS_CHNANGING_LOADS_FOR_ALLSUs_Coop_PPU(.0).csv'); 
            succscoop15=csvread ('SuccessfulTransmission_VS_CHNANGING_LOADS_FOR_ALLSUs_Coop_PPU(.15).csv'); 
            succscoop25=csvread ('SuccessfulTransmission_VS_CHNANGING_LOADS_FOR_ALLSUs_Coop_PPU(.25).csv'); 
           
            
            %%%%%%% importing the first colume of each trail to get the graph going on 
            
            x9= succs00 (:,1) ;% this is the results from having 5 SU 
            y9= succs15 (:,1) ;% this is the results from having 8 SU 
            z9= succs25 (:,1); % this is the results from having 10 SU
            x9coop= succscoop00 (:,1) ;% this is the results from having 5 SU 
            y9coop= succscoop15 (:,1); % this is the results from having 8 SU 
            z9coop= succscoop25 (:,1) ;% this is the results from having 10 SU
            
            %%%%%%%%%% the Drawing process 
            hold (app.UIAxes_9)
            plot(app.UIAxes_9,x9,'Color','blue','LineWidth',2.0,'Marker','*');
            plot(app.UIAxes_9,y9,'Color','red','linewidth',2.0,'LineStyle','-.','Marker','o');
            plot(app.UIAxes_9,z9,'Color','green','LineWidth',2.0,'LineStyle','-.','Marker','s');
            plot(app.UIAxes_9,x9coop,'Color','black','LineWidth',2.0,'Marker','x');
            plot(app.UIAxes_9,y9coop,'Color','black','linewidth',2.0,'LineStyle','-.','Marker','+');
            plot(app.UIAxes_9,z9coop,'Color','black','LineWidth',2.0,'LineStyle','-.','Marker','hexagram');
            xlabel(app.UIAxes_9,'SU ID','Fontweight','Bold');
            ylabel(app.UIAxes_9,'Average Value of Used Bands for each SU  ','Fontweight','Bold');
            title (app.UIAxes_9,'Changing The Load VS Bands Taken For SUs for all SUs','Fontweight','Bold');
            legend (app.UIAxes_9,'Probabilty Of ACtivation 0.0 ','Probabilty Of ACtivation 0.15','Probabilty Of ACtivation 0.25 ','Probabilty Of ACtivation 0.0 cooperative  ','Probabilty Of ACtivation 0.15 cooperative','Probabilty Of ACtivation 0.25 cooperative');
            grid on;
            
            
            
            
        end
    end

    % App initialization and construction
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure
            app.UIFigure = uifigure;
            app.UIFigure.Position = [100 100 640 480];
            app.UIFigure.Name = 'UI Figure';
            setAutoResize(app, app.UIFigure, true)

            % Create TabGroup
            app.TabGroup = uitabgroup(app.UIFigure);
            app.TabGroup.Position = [1 1 640 480];

            % Create MainTab
            app.MainTab = uitab(app.TabGroup);
            app.MainTab.Title = 'Main ';
            app.MainTab.Units = 'pixels';

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel = uilabel(app.MainTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel.Position = [170 323 302 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel.Text = ' switch ON the Simulator  Plotter';

            % Create AfteryouputthefilesswitchONtheSimulatorSwitch
            app.AfteryouputthefilesswitchONtheSimulatorSwitch = uiswitch(app.MainTab, 'toggle');
            app.AfteryouputthefilesswitchONtheSimulatorSwitch.ValueChangedFcn = createCallbackFcn(app, @AfteryouputthefilesswitchONtheSimulatorSwitchValueChanged, true);
            app.AfteryouputthefilesswitchONtheSimulatorSwitch.Position = [295 153 51 114];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_11
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_11 = uilabel(app.MainTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_11.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_11.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_11.Position = [180 400 280 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_11.Text = 'State of the Art CRN simulator';

            % Create CRNSimulatorBetaV02Label
            app.CRNSimulatorBetaV02Label = uilabel(app.MainTab);
            app.CRNSimulatorBetaV02Label.FontWeight = 'bold';
            app.CRNSimulatorBetaV02Label.Position = [245 28 151 15];
            app.CRNSimulatorBetaV02Label.Text = 'CRN Simulator Beta V.02 ';

            % Create ThroughputTab
            app.ThroughputTab = uitab(app.TabGroup);
            app.ThroughputTab.Title = 'Throughput';
            app.ThroughputTab.Units = 'pixels';

            % Create UIAxes_1
            app.UIAxes_1 = uiaxes(app.ThroughputTab);
            title(app.UIAxes_1, 'Title');
            xlabel(app.UIAxes_1, 'X');
            ylabel(app.UIAxes_1, 'Y');
            app.UIAxes_1.Position = [25 99 592 339];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_2
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_2 = uilabel(app.ThroughputTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_2.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_2.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_2.Position = [266.5 51 109 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_2.Text = 'Throughput';

            % Create UtilizationTab
            app.UtilizationTab = uitab(app.TabGroup);
            app.UtilizationTab.Title = 'Utilization';
            app.UtilizationTab.Units = 'pixels';

            % Create UIAxes_2
            app.UIAxes_2 = uiaxes(app.UtilizationTab);
            title(app.UIAxes_2, 'Title');
            xlabel(app.UIAxes_2, 'X');
            ylabel(app.UIAxes_2, 'Y');
            app.UIAxes_2.Position = [29 76 583 333];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_3
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_3 = uilabel(app.UtilizationTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_3.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_3.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_3.Position = [274.5 51 93 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_3.Text = 'Utilization';

            % Create SuSUCESSFULtxTab
            app.SuSUCESSFULtxTab = uitab(app.TabGroup);
            app.SuSUCESSFULtxTab.Title = 'Su SUCESSFUL tx';
            app.SuSUCESSFULtxTab.Units = 'pixels';

            % Create UIAxes_3
            app.UIAxes_3 = uiaxes(app.SuSUCESSFULtxTab);
            title(app.UIAxes_3, 'Title');
            xlabel(app.UIAxes_3, 'X');
            ylabel(app.UIAxes_3, 'Y');
            app.UIAxes_3.Position = [53 88 535 328];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_4
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_4 = uilabel(app.SuSUCESSFULtxTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_4.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_4.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_4.Position = [234 51 174 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_4.Text = 'Su SUCESSFUL tx';

            % Create SUcollisionsTab
            app.SUcollisionsTab = uitab(app.TabGroup);
            app.SUcollisionsTab.Title = 'SU collisions';
            app.SUcollisionsTab.Units = 'pixels';

            % Create UIAxes_4
            app.UIAxes_4 = uiaxes(app.SUcollisionsTab);
            title(app.UIAxes_4, 'Title');
            xlabel(app.UIAxes_4, 'X');
            ylabel(app.UIAxes_4, 'Y');
            app.UIAxes_4.Position = [53 88 535 328];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_5
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_5 = uilabel(app.SUcollisionsTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_5.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_5.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_5.Position = [260.5 51 121 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_5.Text = 'SU collisions';

            % Create PUinterferanceRatioTab
            app.PUinterferanceRatioTab = uitab(app.TabGroup);
            app.PUinterferanceRatioTab.Title = 'PU interferance Ratio';
            app.PUinterferanceRatioTab.Units = 'pixels';

            % Create UIAxes_5
            app.UIAxes_5 = uiaxes(app.PUinterferanceRatioTab);
            title(app.UIAxes_5, 'Title');
            xlabel(app.UIAxes_5, 'X');
            ylabel(app.UIAxes_5, 'Y');
            app.UIAxes_5.Position = [53 88 535 328];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_6
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_6 = uilabel(app.PUinterferanceRatioTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_6.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_6.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_6.Position = [222 51 198 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_6.Text = 'PU interferance Ratio';

            % Create SucessfulS4Tab
            app.SucessfulS4Tab = uitab(app.TabGroup);
            app.SucessfulS4Tab.Title = 'Sucessful S4';
            app.SucessfulS4Tab.Units = 'pixels';

            % Create UIAxes_6
            app.UIAxes_6 = uiaxes(app.SucessfulS4Tab);
            title(app.UIAxes_6, 'Title');
            xlabel(app.UIAxes_6, 'X');
            ylabel(app.UIAxes_6, 'Y');
            app.UIAxes_6.Position = [53 88 535 328];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_7
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_7 = uilabel(app.SucessfulS4Tab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_7.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_7.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_7.Position = [224.5 51 193 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_7.Text = 'Sucessful S4 vs time';

            % Create CooperatvesensingFATab
            app.CooperatvesensingFATab = uitab(app.TabGroup);
            app.CooperatvesensingFATab.Title = 'Cooperatve sensing FA';
            app.CooperatvesensingFATab.Units = 'pixels';

            % Create UIAxes_7
            app.UIAxes_7 = uiaxes(app.CooperatvesensingFATab);
            title(app.UIAxes_7, 'Title');
            xlabel(app.UIAxes_7, 'X');
            ylabel(app.UIAxes_7, 'Y');
            app.UIAxes_7.Position = [53 88 535 328];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_8
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_8 = uilabel(app.CooperatvesensingFATab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_8.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_8.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_8.Position = [213.5 51 215 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_8.Text = 'Cooperatve sensing FA';

            % Create CooperativeSensingMDTab
            app.CooperativeSensingMDTab = uitab(app.TabGroup);
            app.CooperativeSensingMDTab.Title = 'Cooperative Sensing MD';
            app.CooperativeSensingMDTab.Units = 'pixels';

            % Create UIAxes_8
            app.UIAxes_8 = uiaxes(app.CooperativeSensingMDTab);
            title(app.UIAxes_8, 'Title');
            xlabel(app.UIAxes_8, 'X');
            ylabel(app.UIAxes_8, 'Y');
            app.UIAxes_8.Position = [53 88 535 328];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_9
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_9 = uilabel(app.CooperativeSensingMDTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_9.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_9.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_9.Position = [205.5 51 231 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_9.Text = 'Cooperative Sensing MD';

            % Create ChangingLoadTab
            app.ChangingLoadTab = uitab(app.TabGroup);
            app.ChangingLoadTab.Title = 'Changing Load';
            app.ChangingLoadTab.Units = 'pixels';

            % Create UIAxes_9
            app.UIAxes_9 = uiaxes(app.ChangingLoadTab);
            title(app.UIAxes_9, 'Title');
            xlabel(app.UIAxes_9, 'X');
            ylabel(app.UIAxes_9, 'Y');
            app.UIAxes_9.Position = [53 88 535 328];

            % Create AfteryouputthefilesswitchONtheSimulatorSwitchLabel_10
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_10 = uilabel(app.ChangingLoadTab);
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_10.HorizontalAlignment = 'center';
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_10.FontSize = 20;
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_10.Position = [250 51 142 26];
            app.AfteryouputthefilesswitchONtheSimulatorSwitchLabel_10.Text = 'Changing Load';
        end
    end

    methods (Access = public)

        % Construct app
        function app = App13()

            % Create and configure components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end