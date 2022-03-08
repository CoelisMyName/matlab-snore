classdef useMyFFTW < coder.fftw.StandaloneFFTW3Interface
     
    methods (Static)
        function th = getNumThreads
            coder.inline('always');
            th = int32(coder.const(8));
        end
        
        function lock()
            coder.cinclude('mylock.h', 'InAllSourceFiles', true);
            coder.inline('always');
            coder.ceval('mylock');
        end
        
        function unlock()
            coder.cinclude('mylock.h', 'InAllSourceFiles', true);
            coder.inline('always');
            coder.ceval('myunlock');
        end
                
        function updateBuildInfo(buildInfo, ctx)
            fftwLocation = 'C:\fftw\x86_64';
            includePath = fullfile(fftwLocation, 'include');
            buildInfo.addIncludePaths(includePath);
            libPath = fullfile(fftwLocation, 'lib');
            
            %Double
            libName1 = 'libfftw3-3';
            [~, libExt] = ctx.getStdLibInfo();
            libName1 = [libName1 libExt];
            addLinkObjects(buildInfo, libName1, libPath, 1000, true, true);
            
            %Single
             libName2 = 'libfftw3f-3';
            [~, libExt] = ctx.getStdLibInfo();
            libName2 = [libName2 libExt];
            addLinkObjects(buildInfo, libName2, libPath, 1000, true, true);
        end
    end           
end