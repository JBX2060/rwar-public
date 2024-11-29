#include <Shared/Rivet.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EMSCRIPTEN
#include <curl/curl.h>
#else
#include <emscripten.h>
#endif

#include <Shared/cJSON.h>

#ifdef RIVET_BUILD
#define BASE_API_URL "https://api.rwar.fun/api/"
#else
#define BASE_API_URL "https://api.rwar.fun/api/"
#endif

#define RR_RIVET_CURL_PROLOGUE                                                 \
    struct curl_slist *list = 0;                                               \
    int err = 0;                                                               \
    CURL *curl = curl_easy_init();                                             \
    assert(curl);                                                              \
    char header[500] = "Authorization: Bearer ";                               \
    list = curl_slist_append(list, strcat(header, lobby_token));               \
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

#define RR_RIVET_CURL_EPILOGUE                                                 \
    err = curl_easy_perform(curl);                                             \
    assert(!err);                                                              \
    curl_easy_cleanup(curl);                                                   \
    curl_slist_free_all(list);

void rr_rivet_lobbies_ready(char const *lobby_token)
{
#ifdef RR_SERVER
    RR_RIVET_CURL_PROLOGUE
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://matchmaker.api.rivet.gg/v1/lobbies/ready");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{}");
    RR_RIVET_CURL_EPILOGUE
#endif
}

void rr_rivet_lobbies_set_closed(char const *lobby_token, int closed)
{
#ifdef RR_SERVER
    cJSON *root = cJSON_CreateObject();
    cJSON_AddBoolToObject(root, "is_closed", closed);
    char *post_data = cJSON_Print(root);

    RR_RIVET_CURL_PROLOGUE
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://matchmaker.api.rivet.gg/v1/lobbies/closed");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
    RR_RIVET_CURL_EPILOGUE

    free(post_data);
    cJSON_Delete(root);
#endif
}

int rr_rivet_players_connected(char const *lobby_token,
                               char const *player_token)
{
#ifdef RR_SERVER
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "player_token", player_token);
    char *post_data = cJSON_Print(root);

    RR_RIVET_CURL_PROLOGUE
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://matchmaker.api.rivet.gg/v1/players/connected");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
    err = curl_easy_perform(curl);
    assert(!err);

    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    free(post_data);
    cJSON_Delete(root);
    curl_easy_cleanup(curl);
    curl_slist_free_all(list);
    return http_code == 200;
#endif
    return 1;
}

void rr_rivet_players_disconnected(char const *lobby_token,
                                   char const *player_token)
{
#ifdef RR_SERVER
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "player_token", player_token);
    char *post_data = cJSON_Print(root);

    RR_RIVET_CURL_PROLOGUE
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://matchmaker.api.rivet.gg/v1/players/disconnected");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
    RR_RIVET_CURL_EPILOGUE

    free(post_data);
    cJSON_Delete(root);
#endif
}

// public token:
// dev_prod.eyJ0eXAiOiJKV1QiLCJhbGciOiJFZERTQSJ9.CLLTu7voMhCy-_b98jEaEgoQj-gzaddwQwOM5O2Q4Xz-AiIhQh8KEgoQSIFSwo_HT6GIhaljrDftExoJMTI3LjAuMC4x.Fji9GZ2J0fgNXFV2sGTIO08DuH5w98TfqjreAuAVURaFqCH37bzDxnd7GY8dgYG-jX2KV_o1Ck42l_u4V2KrBw


void rr_rivet_lobbies_find(void *captures, char const *region)
{
    puts("<rr_rivet::lobby_find>");
#ifdef EMSCRIPTEN
    EM_ASM(
        {
            try
            {
                fetch("https://matchmaker.api.rivet.gg/v1/lobbies/find", {
                    "headers" : {
                        "Authorization" :
                            // clang-format off
                            "Bearer dev_prod.eyJ0eXAiOiJKV1QiLCJhbGciOiJFZERTQSJ9.CLLTu7voMhCy-_b98jEaEgoQj-gzaddwQwOM5O2Q4Xz-AiIhQh8KEgoQSIFSwo_HT6GIhaljrDftExoJMTI3LjAuMC4x.Fji9GZ2J0fgNXFV2sGTIO08DuH5w98TfqjreAuAVURaFqCH37bzDxnd7GY8dgYG-jX2KV_o1Ck42l_u4V2KrBw"
                        // clang-format on
                    },
                    "method" : "POST",
                    "body" : $1 ? '{"game_modes":["default"],"regions":["' +
                                      UTF8ToString($1) + '"]}'
                                : '{"game_modes":["default"]}'
                })
                    .then(function(r) { return r.json(); })
                    .then(function(json) {
                        const host = json["ports"]["default"]["hostname"];
                        const token = "Bearer " + json["player"]["token"];
                        const $host = _malloc(host.length + 1);
                        const $token = _malloc(1 + token.length);
                        HEAPU8.set(new TextEncoder().encode(host), $host);
                        HEAPU8.set(new TextEncoder().encode(token), $token);
                        HEAPU8[$host + host.length] = 0;
                        HEAPU8[$token + token.length] = 0;
                        _rr_rivet_lobby_on_find(
                            $host, $token, json["ports"]["default"]["port"],
                            $0);
                        _free($host);
                        _free($token);
                    })
                    .catch(function(error) { console.log(error); });
            }
            catch (e)
            {
                console.log(e);
            }
        },
        captures, region);
#endif
}

void rr_rivet_lobbies_join(void *captures, char const *lobby_id)
{
    printf("<rr_rivet::lobby_join::%s>\n", lobby_id);
#ifdef EMSCRIPTEN
    EM_ASM(
        {
            fetch("https://matchmaker.api.rivet.gg/v1/lobbies/join", {
                "headers" : {
                    "Authorization" :
                        // clang-format off
                        "Bearer dev_prod.eyJ0eXAiOiJKV1QiLCJhbGciOiJFZERTQSJ9.CLLTu7voMhCy-_b98jEaEgoQj-gzaddwQwOM5O2Q4Xz-AiIhQh8KEgoQSIFSwo_HT6GIhaljrDftExoJMTI3LjAuMC4x.Fji9GZ2J0fgNXFV2sGTIO08DuH5w98TfqjreAuAVURaFqCH37bzDxnd7GY8dgYG-jX2KV_o1Ck42l_u4V2KrBw"
                    // clang-format on
                },
                "method" : "POST",
                "body" : '{"lobby_id":"' + UTF8ToString($1) + '"}'
            })
                .then(function(r) { return r.json(); })
                .then(function(json) {
                    const host = json["ports"]["default"]["hostname"];
                    const token = "Bearer " + json["player"]["token"];
                    const $host = _malloc(host.length + 1);
                    const $token = _malloc(1 + token.length);
                    HEAPU8.set(new TextEncoder().encode(host), $host);
                    HEAPU8.set(new TextEncoder().encode(token), $token);
                    HEAPU8[$host + host.length] = 0;
                    HEAPU8[$token + token.length] = 0;
                    _rr_rivet_lobby_on_find(
                        $host, $token, json["ports"]["default"]["port"], $0);
                    _free($host);
                    _free($token);
                })
                .catch(
                    function(error) { _rr_rivet_lobby_on_find(0, 0, 0, $0); });
        },
        captures, lobby_id);
#endif
}

void rr_rivet_link_account(char *game_user, char *api_password, void *captures)
{
    puts("<rr_rivet::account_link>");
#ifdef EMSCRIPTEN
    // clang-format off
    EM_ASM(
        {
            let token = UTF8ToString($0);

            // TODO: LINK ACCOUNT
            w = window.open(r["identity_link_url"], "", "width=600,height=600");
            let h = fetch("https://api.rivet.gg/identity/game-links?identity_link_token=" + r["identity_link_token"], {
                });
            handle(h);
        }, game_user, BASE_API_URL, api_password);
    // clang-format on
#endif
}


void rr_rivet_identities_create_guest(void *captures)
{
    puts("<rr_rivet::attempt_login>");
#ifdef EMSCRIPTEN
// clang-format off
EM_ASM({
(async function() {
    // Check for discord callback!
    const fragment = new URLSearchParams(window.location.hash.slice(1));
    const access_token = fragment.get('access_token');
    const token_type = fragment.get('token_type');

    if (access_token && token_type)
    {
        await fetch("https://api.rwar.fun/api/account_link?username=" + window.localStorage["rivet_account_uuid"] + "&access_token=" + access_token, {
            "method": "GET",
            "headers": {
                "Authorization": "Bearer dev_prod.eyJ0eXAiOiJKV1QiLCJhbGciOiJFZERTQSJ9.CLLTu7voMhCy-_b98jEaEgoQj-gzaddwQwOM5O2Q4Xz-AiIhQh8KEgoQSIFSwo_HT6GIhaljrDftExoJMTI3LjAuMC4x.Fji9GZ2J0fgNXFV2sGTIO08DuH5w98TfqjreAuAVURaFqCH37bzDxnd7GY8dgYG-jX2KV_o1Ck42l_u4V2KrBw"
            },
        }).then(data => data.json())
        .then(data => {
            if (data.code != "ERROR")
                if (data["username"] && data["username"] !== "null" && data["username"] !== "undefined") {
                    window.localStorage["rivet_account_uuid"] = data["username"];
                    window.history.replaceState({}, document.title, window.location.pathname);
                    alert("Account linked successfully!");
                }
        })
    }

    if (window.localStorage["rivet_account_uuid"] === "undefined" || window.localStorage["rivet_account_uuid"] === "null") {
        delete window.localStorage["rivet_account_uuid"];
    }


    let api = UTF8ToString($1);
    function on_account(data)
    {
        // Allocate memory for strings
        const $token = _malloc(data["identity_token"].length + 1); // 1
        const $avatar_url = _malloc(data["identity"]["avatar_url"].length + 1); // 2
        const $name = _malloc(data["identity"]["display_name"].length + 1); // 3
        const $uuid = _malloc(data["username"].length + 1); // 4
        const $account_number = _malloc(6); // 5

        // Copy strings into the allocated memory
        HEAPU8[$token + data["identity_token"].length] = 0; // 1 null terminate
        HEAPU8[$avatar_url + data["identity"]["avatar_url"].length] = 0; // 2
        HEAPU8[$name + data["identity"]["display_name"].length] = 0; // 3
        HEAPU8[$uuid + data["username"].length] = 0; // 4
        HEAPU8[$account_number + 5] = 0; // 5

        HEAPU8.set(new TextEncoder().encode(data["identity_token"]), $token); // 1
        HEAPU8.set(new TextEncoder().encode(data["identity"]["avatar_url"]), $avatar_url); // 2
        HEAPU8.set(new TextEncoder().encode(data["identity"]["display_name"]), $name); // 3
        HEAPU8.set(new TextEncoder().encode(data["username"]), $uuid); // 4
        HEAPU8.set(new TextEncoder().encode("#"+data["identity"]["account_number"].toString().padStart(4, "0")), $account_number); // 5

        // Call the C function
        _rr_rivet_on_log_in($token, $avatar_url, $name, $account_number, $uuid, +data["identity"]["is_game_linked"], $0);

        // Free the allocated memory
        _free($uuid);
        _free($token);
        _free($avatar_url);
        _free($name);
        _free($account_number);
    }

    function attempt(key)
    {
        // EM_ASM doesn't support object literals
        const data = {};
        data["identity_token"] = "token";
        data["identity"] = {};
        data["identity"]["avatar_url"] = "url";
        data["identity"]["display_name"] = "Guest";
        data["identity"]["identity_id"] = "";
        data["identity"]["account_number"] = "0000";
        data["identity"]["is_game_linked"] = false;

        // First time launching the game, we need to create a new account
        if (!window.localStorage[key])
        {
            function uuidv4() {
                return "10000000-1000-4000-8000-100000000000".replace(/[018]/g, c =>
                    (+c ^ crypto.getRandomValues(new Uint8Array(1))[0] & 15 >> +c / 4).toString(16)
                );
            }
            data["username"] = uuidv4();
            window.localStorage["rivet_account_uuid"] = data["username"];
            on_account(data);
        }
        else
        {
            // We already played before. Either have a rivet account or playing as a guest.
            function login()
            {
                // We're already migrated, just log in
                fetch("https://api.rwar.fun/api/" + "user_get_identity" + "?existing_identity_token=" + window.localStorage[key], {
                    "method": "GET",
                    "headers": {
                        "Authorization": "Bearer dev_prod.eyJ0eXAiOiJKV1QiLCJhbGciOiJFZERTQSJ9.CLLTu7voMhCy-_b98jEaEgoQj-gzaddwQwOM5O2Q4Xz-AiIhQh8KEgoQSIFSwo_HT6GIhaljrDftExoJMTI3LjAuMC4x.Fji9GZ2J0fgNXFV2sGTIO08DuH5w98TfqjreAuAVURaFqCH37bzDxnd7GY8dgYG-jX2KV_o1Ck42l_u4V2KrBw"
                    },
                }).then(data => data.json())
                .then(data => {
                    if (data.code == "ERROR")
                        throw data;
                    if (!window.localStorage["rivet_account_uuid"])
                        window.localStorage["rivet_account_uuid"] = data["username"];

                    window.localStorage["rivet_migration_uuid"] = data["username"];
                    on_account(data);
                }).catch(function(e)
                {
                    alert("Login failed: please reload");
                });
            }

            // Migrate from rivet
            if (!window.localStorage["rivet_migration_uuid"]) {
                // get current time
                const before_time = Date.now();
                fetch("https://api.rivet.gg/identity/identities", {
                    "method": "POST",
                    "body": JSON.stringify({
                        "existing_identity_token": window.localStorage["DO_NOT_SHARE_rivet_account_token"]
                    }),
                    "headers": {
                        "Authorization": "Bearer dev_prod.eyJ0eXAiOiJKV1QiLCJhbGciOiJFZERTQSJ9.CLLTu7voMhCy-_b98jEaEgoQj-gzaddwQwOM5O2Q4Xz-AiIhQh8KEgoQSIFSwo_HT6GIhaljrDftExoJMTI3LjAuMC4x.Fji9GZ2J0fgNXFV2sGTIO08DuH5w98TfqjreAuAVURaFqCH37bzDxnd7GY8dgYG-jX2KV_o1Ck42l_u4V2KrBw"
                    },
                }).then(data => data.json())
                .then(data => {
                    if (data.code == "ERROR")
                        throw data;

                    const join_date = new Date(data["identity"]["join_ts"]);
                    const join_time_ms = join_date.getTime();
                    const current_time_ms = Date.now();
                    const time_difference = current_time_ms - join_time_ms;

                    if (time_difference < 120000) {
                        // ALERT! This means the user used rivet to log in. Move on to the second else statement
                        login();
                        window.localStorage["rivet_migration_uuid"] = window.localStorage[key];
                        return; // Exit the current function to prevent further execution
                    }

                    // Get the account number and set it as the rivet_account_uuid
                    window.localStorage["before_migration_rivet_account_uuid"] = window.localStorage[key];

                    // Update to the new account. Should work fine even without a reload afterwards.
                    window.localStorage[key] = data["identity"]["identity_id"];
                    window.localStorage["rivet_migration_uuid"] = window.localStorage[key];

                    // Prevent length error
                    data["username"] = data["identity"]["identity_id"];

                    on_account(data);
                })
                .catch(function(e)
                {
                   alert("Rivet Migration failed. Please ask the devs to help you out.");
                });
            } else {
                login();
            }
        }
    }
    attempt("rivet_account_uuid");
    })();
    }, captures);
#endif
}
