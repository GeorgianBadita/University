package ro.ubbcluj.cs.geo.myFirstAndroidApp.auth.login

data class LoginFormState(
    val usernameError: Int? = null,
    val passwordError: Int? = null,
    val isDataValid: Boolean = false
)
