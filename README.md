
# DeleteAnything
Utilizing a Vulnerable Driver to allow for unprivileged deletion of any file!

## Please Note
I didnt intend on releasing this, i had plans to add more stuff to this project however, lately im not in the mood. The code I wrote for this is very rough and is meant to serve as an example.

## Usage
- Simply install and start 'IUForceDelete.sys' 
```
sc create fd type=kernel binpath="IUForceDelete_PATH_HERE"
sc start fd
```
- Run DeleteAnything!

## Vulnerable Driver
The driver used is 'IUForceDelete.sys', which is an old version of the current ( still vulnerable ) driver 'IMFForceDelete.sys'. Usage of 'IUForceDelete.sys' is notable as it was never used by the publisher and unlike 'IMFForceDelete.sys' it is not listed in vulnerable driver databases and is (was) unlikely to ever be noticed due to not being used anywhere.

## CVE-2019-6494
This code also functions as a poc / example of CVE-2019-6494 with 'IMFForceDelete.sys', which functions identically to 'IUForceDelete.sys' ( note: 'IMFForceDelete.sys' is known to be malicious and is in many vulnerable driver databases ).

## Videos & Stuff 
[![Video of use, deleting windows defender]()](https://youtu.be/xxXF54XFrE0)

