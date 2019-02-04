
# react-native-landmarks

## Getting started

`$ npm install react-native-landmarks --save`

### Mostly automatic installation

`$ react-native link react-native-landmarks`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-landmarks` and add `RNLandmarks.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNLandmarks.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.dovetailstudios.landmarks.RNLandmarksPackage;` to the imports at the top of the file
  - Add `new RNLandmarksPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-landmarks'
  	project(':react-native-landmarks').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-landmarks/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-landmarks')
  	```


## Usage
```javascript
import RNLandmarks from 'react-native-landmarks';

// TODO: What to do with the module?
RNLandmarks;
```
  