#go into the build directory
cd build

dotnet sln projectname.sln remove ALL_BUILD.vcxproj
dotnet sln projectname.sln remove ZERO_CHECK.vcxproj

#cd to the original directory
cd ..