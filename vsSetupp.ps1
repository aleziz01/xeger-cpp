#go into the build directory
cd build

dotnet sln xeger.sln remove ALL_BUILD.vcxproj
dotnet sln xeger.sln remove ZERO_CHECK.vcxproj

#cd to the original directory
cd ..