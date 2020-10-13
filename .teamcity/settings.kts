import jetbrains.buildServer.configs.kotlin.v2019_2.*
import jetbrains.buildServer.configs.kotlin.v2019_2.buildSteps.script
import jetbrains.buildServer.configs.kotlin.v2019_2.triggers.vcs

/*
The settings script is an entry point for defining a TeamCity
project hierarchy. The script should contain a single call to the
project() function with a Project instance or an init function as
an argument.

VcsRoots, BuildTypes, Templates, and subprojects can be
registered inside the project using the vcsRoot(), buildType(),
template(), and subProject() methods respectively.

To debug settings scripts in command-line, run the

    mvnDebug org.jetbrains.teamcity:teamcity-configs-maven-plugin:generate

command and attach your debugger to the port 8000.

To debug in IntelliJ Idea, open the 'Maven Projects' tool window (View
-> Tool Windows -> Maven Projects), find the generate task node
(Plugins -> teamcity-configs -> teamcity-configs:generate), the
'Debug' option is available in the context menu for the task.
*/

version = "2020.1"

data class BuildFlagValue(val value: Any, val name: String? = null) {
    override fun toString() = name ?: value.toString()
}

data class BuildFlag(val flag: String, val value: BuildFlagValue)
data class BuildFlagDef(val flag: String, val values: List<BuildFlagValue>)

val boards = listOf(
        "esp32",
        "mega2560",
        "uno"
)

val displays = listOf(
        BuildFlagValue(0, "LCD"),
        BuildFlagValue(1, "Headless")
)

project {
    for (board in boards) {
        for (display in displays) {
            buildType(buildFirmware(board, display))
        }
    }
}

fun buildFirmware(board: String, display: BuildFlagValue): BuildType {
    return BuildType {
        id("""${board}_${display.value}""")
        name = """$board ($display)"""

        vcs {
            root(DslContext.settingsRoot, "+:Software/Arduino code/OpenAstroTracker => .")
        }

        steps {
            script {
                name = "Build"
                scriptContent = """platformio run -e $board"""
            }
        }
    }
}

//object Firmware : BuildType({
//    name = "Firmware"
//
//    vcs {
//        root(DslContext.settingsRoot, "+:Software/Arduino code/OpenAstroTracker => .")
//    }
//
//    steps {
//        script {
//            name = "Build"
//            scriptContent = "platformio run"
//        }
//    }
//
//    triggers {
//        vcs {
//        }
//    }
//})
