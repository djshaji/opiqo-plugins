# Java Theme System - Dependencies

The Java theme classes require the following dependencies:

## Required Dependencies

### Google Gson
- **Purpose**: JSON parsing and serialization
- **Version**: 2.8.9 or later
- **Maven**: `com.google.code.gson:gson:2.8.9`
- **Gradle**: `com.google.code.gson:gson:2.8.9`

### Android Framework
- **Purpose**: Android Views, Context, Resources
- **Version**: API level 21+
- **Gradle**: (built-in with Android SDK)

## Gradle Setup

Add to your `build.gradle` (Module: app):

```gradle
dependencies {
    // Gson for JSON processing
    implementation 'com.google.code.gson:gson:2.10'
    
    // Android framework (implicit)
    // implementation(...) // Android SDK dependencies
}
```

## Maven Setup

Add to your `pom.xml`:

```xml
<dependency>
    <groupId>com.google.code.gson</groupId>
    <artifactId>gson</artifactId>
    <version>2.10</version>
</dependency>
```

## Package Structure

```
com.opiqo.theme/
├── ThemeManager.java         # Requires: Gson, Android Framework
├── SkinParser.java           # Requires: Gson
├── ColorUtils.java           # Requires: Android Framework
└── UserTheme.java            # Requires: Nothing (POJO)
```

## Import Statements

All Java files require these imports:

```java
// ThemeManager
import android.content.Context;
import android.content.res.AssetManager;
import android.util.Log;
import com.google.gson.Gson;
import java.io.*;
import java.util.*;

// SkinParser
import android.util.Log;
import com.google.gson.Gson;
import com.google.gson.JsonSyntaxException;
import java.util.*;

// ColorUtils
import android.graphics.Color;
import android.util.Log;

// UserTheme
// No external imports required
```

## Optional Dependencies (for advanced features)

### Retrofit (for remote skin loading)
```gradle
implementation 'com.squareup.retrofit2:retrofit:2.9.0'
implementation 'com.squareup.retrofit2:converter-gson:2.9.0'
```

### Room Database (for skin caching)
```gradle
implementation 'androidx.room:room-runtime:2.4.2'
annotationProcessor 'androidx.room:room-compiler:2.4.2'
```

## Version Compatibility

| Component | Min API | Target API |
|-----------|---------|-----------|
| ThemeManager | 21 | 31+ |
| SkinParser | 21 | 31+ |
| ColorUtils | 21 | 31+ |
| UserTheme | 16 | 31+ |
| Gson | - | 2.8.9+ |

## Gradle Dependency Management

### Lock specific versions:
```gradle
configurations.all {
    resolutionStrategy {
        force 'com.google.code.gson:gson:2.10'
    }
}
```

### Exclude transitive dependencies:
```gradle
implementation('com.google.code.gson:gson:2.10') {
    exclude group: 'some.group', module: 'some.module'
}
```

## Troubleshooting

### JsonSyntaxException
Ensure Gson is properly initialized and skin JSON is valid.

### ClassNotFoundException for Android classes
Make sure Android SDK is installed and gradle sync is complete.

### Memory issues with large JSON
Use streaming JSON parser instead of loading entire file:
```java
JsonReader reader = new JsonReader(new FileReader(skinFile));
PluginSkin skin = gson.fromJson(reader, PluginSkin.class);
reader.close();
```

## ProGuard/R8 Configuration

If using ProGuard/R8 for code shrinking, add to `proguard-rules.pro`:

```proguard
# Gson
-keep class com.google.gson.** { *; }
-keep class ** extends com.google.gson.TypeAdapter
-keep class ** implements com.google.gson.JsonDeserializer
-keep class ** implements com.google.gson.JsonSerializer

# Opiqo theme classes
-keep class com.opiqo.theme.** { *; }
-keepclassmembers class com.opiqo.theme.** { *; }

# Preserve all inner classes (needed for data classes)
-keep class com.opiqo.theme.**$* { *; }
```

## Building Without Gradle

If building without Gradle, ensure:
1. Android SDK classes are in classpath
2. Gson JAR is in classpath
3. Java 8+ compiler

```bash
javac -cp gson.jar:android.jar com/opiqo/theme/*.java
```

## CI/CD Integration

### GitHub Actions Example
```yaml
- name: Setup Gradle
  uses: gradle/gradle-build-action@v2

- name: Build with Gradle
  run: ./gradlew build
```

The Gradle build system will automatically download and manage Gson.
