package ro.ubbcluj.cs.geo.myFirstAndroidApp.auth.data

import ro.ubbcluj.cs.geo.myFirstAndroidApp.auth.data.remote.RemoteAuthDataSource
import ro.ubbcluj.cs.geo.myFirstAndroidApp.core.Api
import ro.ubbcluj.cs.geo.myFirstAndroidApp.core.Result

object AuthRepository {
    var user: User? = null
        private set

    val isLoggedIn: Boolean
        get() = user != null

    init {
        user = null
    }

    fun logout() {
        user = null
        Api.tokenInterceptor.token = null
    }

    suspend fun login(username: String, password: String): Result<TokenHolder> {
        val user = User(username, password)
        val result = RemoteAuthDataSource.login(user)
        if (result is Result.Success<TokenHolder>) {
            setLoggedInUser(user, result.data)
        }
        return result
    }

    private fun setLoggedInUser(user: User, tokenHolder: TokenHolder) {
        this.user = user
        Api.tokenInterceptor.token = tokenHolder.token
    }
}
