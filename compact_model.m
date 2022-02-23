%% compact model
mdl = load('adaboost_23.mat').adaStump;
saveLearnerForCoder(mdl, 'compacted_model');
%% load model
cpt = loadLearnerForCoder('compacted_model');